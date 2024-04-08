import QtQuick 2.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.15
import QtQuick.Dialogs 1.0
import QtQuick.Layouts 1.15
import QtQuick.Extras 1.4


Item {

    property bool isActiveTab: false
    property int intHeight : 500
    property int intWidth : 500
    property string directionprop: "Forward"

    Rectangle{
        id: base

        color: "#032824"
        anchors.fill: parent
        anchors.margins: 10

        ColumnLayout{
            anchors.fill: parent
            RowLayout{
                DigitalGuage{
                    id: digiguageIa
                    variablename: "Ia"
                    unit: "mA"
                }
                DigitalGuage{
                    id: digiguageIb
                    variablename: "Ib"
                    unit: "mA"
                }
                DigitalGuage{
                    id: digiguageIc
                    variablename: "Ic"
                    unit: "mA"
                }
                Rectangle {
                    color: "#00000000";
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.minimumHeight: base * 0.75
                    Layout.preferredHeight: base * 0.85
                    SpeedGuage{
                        id: gauge
                        anchors.fill: parent
                        anchors.topMargin: 10
                        focus: true
                    }
                    DigitalGuage{
                        // width: gauge.width/3; height:gauge.width/3;
                        // radius: gauge.width/3
                        // color: "#3b3b3b"
                        anchors.centerIn: gauge
                        z:1
                        unit: "RPM"
                        variablename: "SPEED"
                    }
                }

                DigitalGuage{
                    id: digiguageVa
                    unit: "V"
                    variablename: "Va"
                }
                DigitalGuage{
                    id: digiguageVb
                    unit: "V"
                    variablename: "Vb"
                }
                DigitalGuage{
                    id: digiguageVc
                    unit: "V"
                    variablename: "Vb"
                }
            }
            RowLayout{
                ControlBoard{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.minimumHeight: base * 0.20
                    Layout.preferredHeight: base * 0.25
                }
            }
        }

    }

}
