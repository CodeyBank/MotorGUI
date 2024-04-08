#ifndef SE_PROTOCOL_H
#define SE_PROTOCOL_H

#include "qvariant.h"
#include <cstdint>
#include <QByteArray>
#define MAX_TXRX_SIZE 50   // max of 64bits
#define MAX_NUMBER_TABLES 8
#define SE_MAX_BUFF_SIZE 50
#define START_SYMBOL_CMD START_SYMBOL
#define START_SYMBOL '+'
#define START_SYMBOL_MEM_RECORD '*'
#define STOP_SYMBOL '-'
#define COMM_QUEUE_SIZE 10
#define MAX_VAR_NAME_CHAR_COUNT 50


struct MemValue_S{
    uint8_t data[MAX_TXRX_SIZE];
    uint8_t size;
};
// custom error codes
enum NCNERROR {
    SUCCESS = 0U,
    FAIL
};
typedef enum NCNERROR error_t;


typedef enum tcommand_types {
    read = 0xA1, write = 0xA2, load = 0xB1
} TCommand;

typedef struct commandheader {
    uint32_t transaction_id;
    TCommand command_type;
} commandheader_t;

typedef enum data_types {
    sU8 = 0x51, sU16, sU32, sFLT, sDFLT
} dt_map;

typedef enum attribute {
    RO = 0xF0, RW, WO
} mem_record_attr;

typedef struct command {
    // size: 5 + 4 + 1 + 8 = 18 + 2
    commandheader_t header;
    qint32 address; // read/write index in the table to avoid use of hashtables
    uint8_t txrx_size;  // tx/rx size
    uint8_t data[MAX_TXRX_SIZE];  // buffer
} command_t;

typedef struct Message_S{

    uint8_t size;
    uint8_t * buffer;
}SE_Message_t;

typedef struct memory_table_record {

    quint32 address;
    uint8_t size;
    dt_map data_type;
    mem_record_attr attribute;
    char name[50];
} mem_record_t;


// perform memory copy of the data byte by byte
// return how many bytes copied

/*
    @brief
    @params
    @return
*/
uint8_t read_table_record(void *address, uint8_t *buffer, uint8_t size);

/*
    @brief
    @params
    @return
*/
error_t parse_command(command_t *in_cmd, const mem_record_t *mem_table);

/*
    @brief
    @params
    @return
*/
uint8_t write_table_record(void *destination, void *source, uint8_t size);

/*
    @brief
    @params
    @return
*/
error_t load_table(const mem_record_t * table);

/*
    @brief
    @params
    @return
*/
void print_buffer(uint8_t *buffer);

/*
    @brief
    @params
    @return
*/
void serialize_cmd_struct(command_t *in_cmd, unsigned char* buffer);

/*
    @brief
    @params
    @return
*/
void serialize_mem_record(const mem_record_t *mem_record, uint8_t * buffer);

/*
    @brief
    @params
    @return
*/
uint8_t get_mem_record_size(const mem_record_t *mem_record);


/*
    @brief
    @params
    @return
*/
uint8_t get_required_buffsize_from_cmdsize(command_t in_cmd);

/*
    @brief Converts a byte array to a character array
    @params
    @return
*/
void convertQByteArrayToUint8Array(const QByteArray &byteArray, uint8_t *uintArray);

/*
    @brief Converts a byte array to a valid command struct
    @params QByteArray byte Received bytearray to be converts
    @return empty struct if invalid data has been sent
*/

command_t rebuild_data(QByteArray &byte);


/*
    @brief Converts a byte array to a character array
    @params
    @return
*/

error_t rebuild_memory_record(QByteArray &byte, memory_table_record &record);


QString convertDT_MAP_ToString(const qint8 & dt);
QString convertAttribute_ToString(const quint8 &attr);
QVariant convertBufferToString(const quint8 *buffer, qint8 size, dt_map type);

#endif // SE_PROTOCOL_H
