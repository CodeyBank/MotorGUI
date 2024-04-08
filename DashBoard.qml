import QtQuick 2.15
import QtQuick.Layouts 1.15

Item {
    property alias rectangle: rectangle
    property alias g1: digitalGuage1
    property alias g2: digitalGuage2
    property alias g3: digitalGuage3
    property alias g4: digitalGuage4
    property alias g5: digitalGuage5
    property alias g6: digitalGuage6
    property alias g7: digitalGuage7
    property alias sG: digitalGuage4
    property alias flt: controlBoard.fault
    property alias control:controlBoard

    id: root

    Rectangle {
        id: rectangle
        color: "#02231f"
        radius: 50
        border.color: "#897d7d"
        border.width: 5
        anchors.fill: parent
        anchors.rightMargin: 10
        ColumnLayout {
            id: columnLayout
            anchors.fill: parent
            spacing: 20

            RowLayout {
                id: rowLayout
                height: 100
                // anchors.left: parent.left
                // anchors.right: parent.right
                spacing: 14
                Layout.leftMargin: 7
                Layout.topMargin: 8
                Layout.rowSpan: 2
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                anchors.leftMargin: 0
                anchors.rightMargin: 0

                Rectangle {
                    id: rectangle1
                    width: 200
                    height: 200
                    color: "#00000000"
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    RowLayout {
                        id: leftrows
                        anchors.fill: parent
                        anchors.leftMargin: 5

                        DigitalGuage {
                            id: digitalGuage1
                            objectName: "digitalGuage1"
                            // anchors.verticalCenter: parent.verticalCenter
                            Layout.fillWidth: true
                            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                            Layout.fillHeight: true
                            Layout.maximumWidth: 300
                            Layout.preferredHeight: 100
                            Layout.preferredWidth: 100
                            Layout.maximumHeight: 150
                            measuredvalue: 0
                            unit: "mA"
                            variablename: "Ia"
                            intFP.intHeading.text:  objectName
                            intFP.onClosed: {
                                varguage1 = intFP.intTaglist.currentText
                            }
                        }

                        DigitalGuage {
                            id: digitalGuage2
                            width: 100
                            objectName: "digitalGuage2"
                            // anchors.verticalCenter: parent.verticalCenter
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            Layout.maximumWidth: 300
                            Layout.preferredHeight: 150
                            Layout.preferredWidth: 100
                            Layout.maximumHeight: 150
                            measuredvalue: 99
                            unit: "mA"
                            variablename: "Ib"
                            intFP.intHeading.text:  objectName
                            intFP.onClosed: {
                                varguage2 = intFP.intTaglist.currentText
                            }
                        }

                        DigitalGuage {
                            id: digitalGuage3
                            objectName: "digitalGuage3"
                            width: 100
                            // anchors.verticalCenter: parent.verticalCenter
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            Layout.maximumWidth: 300
                            Layout.preferredHeight: 150
                            Layout.preferredWidth: 100
                            Layout.maximumHeight: 150
                            measuredvalue: 0
                            unit: "mA"
                            variablename: "Ic"
                            intFP.intHeading.text:  objectName
                            intFP.onClosed: {
                                varguage3 = intFP.intTaglist.currentText
                            }
                        }
                    }
                }

                Rectangle {
                    id: rectangle2
                    width: 200
                    height: 200
                    color: "#00000000"
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    SpeedGuage {
                        property string mappedVariable : ""


                        id: digitalGuage4
                        objectName: "digitalGuage4"
                        anchors.fill: parent
                        Layout.fillWidth: false
                        Layout.fillHeight: true
                        Layout.maximumWidth: 150
                        Layout.preferredHeight: 400
                        Layout.preferredWidth: 400
                        Layout.maximumHeight: 150
                        intGauge.value: helperguage.measuredvalue

                        MouseArea{
                            anchors.fill: parent
                            onEntered: {
                                digitalGuage4.focus = true
                            }
                        }
                        intGauge.onValueChanged:{
                            helperguage.measuredvalue = Math.ceil(intGauge.value)

                        }


                    }
                    DigitalGuage{
                        property string mappedVariable : ""
                        id: helperguage
                        objectName: "helperguage"
                        anchors.centerIn: digitalGuage4
                        height: 150
                        width: 150
                        unit: "RPM"
                        variablename: "x10"
                        measuredvalue: 0
                        z:1
                       intFP.intHeading.text:  objectName
                       intFP.onClosed: {
                           varguage4 = intFP.intTaglist.currentText
                       }
                    }
                }

                Rectangle {
                    id: rectangle3
                    width: 200
                    height: 200
                    color: "#00000000"
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    RowLayout {
                        id: rowLayout1
                        anchors.fill: parent
                        anchors.rightMargin: 20
                        DigitalGuage {
                            property string mappedVariable : ""
                            id: digitalGuage5
                            objectName: "digitalGuage5"
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            Layout.maximumWidth: 300
                            Layout.preferredHeight: 150
                            Layout.preferredWidth: 100
                            Layout.maximumHeight: 150
                            measuredvalue: 0
                            unit: "mV"
                            variablename: "Va"
                            intFP.intHeading.text:  objectName
                            intFP.onClosed: {
                                varguage5 = intFP.intTaglist.currentText
                            }

                        }

                        DigitalGuage {
                            property string mappedVariable : ""
                            id: digitalGuage6
                            objectName: "digitalGuage6"
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            Layout.maximumWidth: 300
                            Layout.preferredHeight: 150
                            Layout.preferredWidth: 100
                            Layout.maximumHeight: 150
                            measuredvalue: 0
                            unit: "mV"
                            variablename: "Vb"
                            intFP.intHeading.text:  objectName
                            intFP.onClosed: {
                                varguage6 = intFP.intTaglist.currentText
                            }
                        }

                        DigitalGuage {
                            property string mappedVariable : ""
                            id: digitalGuage7
                            objectName: "digitalGuage7"
                            width: 100
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            Layout.maximumWidth: 300
                            Layout.preferredHeight: 150
                            Layout.preferredWidth: 100
                            Layout.maximumHeight: 150
                            measuredvalue: 0
                            intFP.intHeading.text:  objectName
                            unit: "mV"
                            variablename: "Vc"
                            intFP.onClosed: {
                                varguage7 = intFP.intTaglist.currentText
                            }
                        }
                    }
                }
            }

            ControlBoard {
                id: controlBoard
                objectName: "controlBoard"
                width: 1000
                height: 100
                // anchors.bottom: parent.bottom
                Layout.maximumHeight: 70
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                anchors.bottomMargin: 10
                Layout.preferredHeight: 50
                Layout.preferredWidth: 850
                Layout.fillHeight: true
                Layout.fillWidth: false
                Layout.bottomMargin: 10
            }
        }
    }

}
