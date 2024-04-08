/*
 * se_communication.c
 *
 *  Created on: Mar 5, 2024
 *      Author: Stanley.Ezeh
 */

#include "seprotocol.h"
#include "string.h"
#include <QDebug>
#include <QDataStream>
#include <stdio.h>

// #include <QByteArray>

int g_table_size;
#define SE_DEBUG

uint8_t read_table_record(void *address, uint8_t *buffer, uint8_t size) {
    uint8_t * src = (uint8_t *)address;
    uint8_t * dst = (uint8_t *)buffer;

    uint8_t count=0;

    for(count=0; count<size; count++){
        *dst = *src;
        dst++;
        src++;
    }

    return count;

}


uint8_t write_table_record(void *destination, void *source, uint8_t size) {

    uint8_t * src = (uint8_t *)source;
    uint8_t * dst = (uint8_t *)destination;

    uint8_t count=0;

    for(count=0; count<size; count++){
        *dst = *src;
        dst++;
        src++;
    }

    return count;
}



void print_buffer(uint8_t *buffer){
    mem_record_t mem_record ={};
    memcpy(&mem_record.address,&buffer[1], 4);
    mem_record.size = buffer[5];
    mem_record.data_type = (dt_map)buffer[6];
    mem_record.attribute = (mem_record_attr)buffer[7];


    //	memcpy((void *)&mem_record.name, &buffer[7], 4);


    printf("Address: 0x%d | size: %d | data_type: %s |attribute : %s |name: ",
             mem_record.address, mem_record.size,
           mem_record.data_type == sU32 ? "sU32" :
               (mem_record.data_type == sU8) ? "sU8" : "sU16",
           mem_record.attribute == RO ? "RO" :
               (mem_record.attribute == RW) ? "RW" : "WO");

    for(int i=8; buffer[i]!='\0'; i++){
        if(buffer[i] == STOP_SYMBOL) break;
        printf("%c", buffer[i]);
    }
    printf("\n");
}

uint8_t get_mem_record_size(const mem_record_t *mem_record){
    uint8_t cnt;
    for(cnt=0; mem_record->name[cnt] !='\0'; cnt++);

    return sizeof(mem_record->address) + sizeof(mem_record->data_type) + \
           sizeof(mem_record->attribute) + sizeof(mem_record->size) +cnt + 2;
}

void serialize_mem_record(const mem_record_t *mem_record, uint8_t * buffer){

    uint8_t cnt;
    for(cnt=0; mem_record->name[cnt] !='\0'; cnt++);

    uint8_t size = get_mem_record_size(mem_record);

    buffer[0] = START_SYMBOL;
    int i=1;

    while(i<size-1){
        switch (i) {
        case 1: // address 4 bytes
            memcpy((void *)&buffer[i], (void*)(&mem_record->address),  4);
            i=4;
            break;
        case 5: // size 1 byte
            memcpy((void *)&buffer[i], (void*)(&mem_record->size),  1);
            break;
        case 6:  // data type 1 byte
            memcpy((void *)&buffer[i], (void*)(&mem_record->data_type),  1);
            break;
        case 7: //attribute 1 byte
            memcpy( (void *)&buffer[i], (void*)(&mem_record->attribute), 1);
            break;
        case 8: //name
            //				sprintf((char *)&buffer[i], me)
            memcpy((void *)&buffer[i], (void*)(mem_record->name),  cnt);
            i+=cnt;
            goto cont; // jump to closing symbol
            break;
        default:
            break;
        }

        i++;
    }
cont:
    buffer[i] = STOP_SYMBOL;

}

// copy, byte-by-byte the entire struct and store in the buffer
void serialize_cmd_struct(command_t *in_cmd, unsigned char* buffer){
    // add start and stop bytes to mark boundary
    uint8_t * cp_buff = buffer;
    *cp_buff = START_SYMBOL;  // start of byte array
    cp_buff++;

    // copy the header
    *(uint32_t*)cp_buff= (uint32_t)in_cmd->header.transaction_id;
    cp_buff+=4;
    *cp_buff = in_cmd->header.command_type;
    cp_buff++;

    // copy the address
    *(uint32_t*)cp_buff = (uint32_t)in_cmd->address;  // we know that the void pointer is 4 bytes
    cp_buff +=4;

    // copy the transmit/receive data size
    *cp_buff = in_cmd->txrx_size;
    cp_buff++;

    // copy the data
    for(int i=0; i<in_cmd->txrx_size; i++){
        *cp_buff = in_cmd->data[i];
        cp_buff++;
    }

    *cp_buff = STOP_SYMBOL; // end of bytearray
}

command_t rebuild_data(QByteArray &byte){
    if(byte[0] != START_SYMBOL) {
        // check if the first value in the buffer is a sentinel
        qInfo()<<"Invalid buffer "<< byte[0];
        return {};
    }

    command_t ret = {};
    uint8_t buffer[MAX_TXRX_SIZE];
    memset(buffer,0, MAX_TXRX_SIZE);
    convertQByteArrayToUint8Array(byte, buffer);
    memcpy((void*)(&ret.header.transaction_id), (void *)&buffer[1], 4);
    memcpy((void*)(&ret.header.command_type), (void *)&buffer[5], 1);
    memcpy((void*)(&ret.address), (void *)&buffer[6], 4);
    ret.txrx_size = buffer[10];
    memcpy((void *)ret.data, &buffer[11], buffer[10]);
    return ret;
}


uint8_t get_required_buffsize_from_cmdsize(command_t in_cmd){
    return 2 + sizeof(in_cmd.address) + in_cmd.txrx_size + sizeof(in_cmd.header.command_type) +sizeof(in_cmd.header.transaction_id) + sizeof(in_cmd.txrx_size);
}


void convertQByteArrayToUint8Array(const QByteArray &byteArray, uint8_t *uintArray) {
    for (int i = 0; i < byteArray.size(); ++i) {
        uintArray[i] = static_cast<uint8_t>(byteArray.at(i));
    }
}


error_t rebuild_memory_record(QByteArray &byte, mem_record_t &record){

    // memory_table_record record = {};

    // ensure that we are only trying to rebuild a valid memory record
    if(byte.at(0) != START_SYMBOL_MEM_RECORD) return FAIL;

    uint8_t buffer[MAX_TXRX_SIZE];
    memset(buffer,0, MAX_TXRX_SIZE);
    convertQByteArrayToUint8Array(byte, buffer);


    uint32_t address=0;
    memcpy((void *)&address, (void *)&buffer[1], 4);
    record.address = (quint32)address;

    record.size = buffer[5];
    record.data_type = (dt_map)buffer[6];
    record.attribute = (mem_record_attr)buffer[7];

    memset((void *)record.name, 0, MAX_VAR_NAME_CHAR_COUNT);
    for(int i=8,j=0; buffer[i]!=STOP_SYMBOL; i++, j++){
        // if(buffer[i] == STOP_SYMBOL) break;
        record.name[j] = buffer[i];
    }

    return SUCCESS;
}

QVariant convertBufferToString(const quint8 *buffer, qint8 size, dt_map type)
{
    QVariant ret;
    switch ((dt_map)type) {
    case sU8:
        ret = (quint8)(buffer[0]);
        break;
    case sU16:
        ret = (quint16)(buffer[0]);
        break;
    case sU32:
        ret = (quint32)(buffer[0]);
        break;
    case sFLT:{
        float number = *(float *)(buffer);
        ret = number;
        break;
    }
    default:
        qInfo("Invalid type sent");
        Q_UNUSED(size)
        break;
    }
    return ret;
}

QString convertDT_MAP_ToString(const qint8 &dt)
{
    QString ret;
    switch ((dt_map)dt) {
    case sU8:
        ret = "sU8";
        break;
    case sU16:
        ret = "sU16";
        break;
    case sU32:
        ret = "sU32";
        break;
    case sFLT:
        ret = "Float";
        break;
    default:
        qInfo("Invalid type sent");
        break;
    }
    return ret;
}

QString convertAttribute_ToString(const quint8 &attr)
{
    QString ret;

    switch ((mem_record_attr)attr) {
    case RO:
        ret = "read only";
        break;
    case RW:
        ret = "read-write";
        break;
    case WO:
        ret = "write only";
        break;
    default:
        qInfo("Invalid attribute sent &d", attr);
        break;
    }

    return ret;
}
