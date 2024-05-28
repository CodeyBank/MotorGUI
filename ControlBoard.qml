import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Item {
    id: item1
    property int boardwidth: 0
    property int boardheight: 90
    property string startStopSwitchText: "Start"
    property string directionSwitch: "Forward"
    property string faulticon: "qrc:/images/icons8-ok-48.png"
    property bool pendingfault: false

    property bool connected: false

    property alias fault: faultrect

    Rectangle {
        id: rectangle
        color: "#025346"
        gradient: Gradient{
            GradientStop {position: 0.0; color: "#025346"}
            GradientStop {position: 0.8; color: "#011512"}
        }
        radius: boardheight
        anchors.fill: parent
        // layer.effect: rectangle

        RowLayout {
            id: rowLayout
            anchors.fill: parent
            spacing: 10

            Rectangle {
                property string mappedVariable : ""
                id: faultrect
                objectName: "faultrect"

                width: 200
                height: 200
                color: pendingfault? "red": "#00000000"
                Layout.fillWidth: true
                Layout.maximumHeight: 60
                Layout.maximumWidth: 60
                Layout.minimumHeight: 40
                Layout.minimumWidth: 40
                Layout.preferredHeight: 50
                Layout.preferredWidth: 50
                Layout.leftMargin: 10
                radius: 50


                Image {
                    id: image
                    anchors.fill: parent
                    source: pendingfault ? "qrc:/images/images/svg_images/icons8-error-64.png" :"qrc:/images/images/svg_images/icons8-ok-48.png"
                    fillMode: Image.PreserveAspectFit
                }
            }

            RoundButton {
                property string mappedVariable : ""
                id: clearFaultsBtn
                objectName: "clearFaultsBtn"
                text: "Clear faults"
                Layout.preferredWidth: 70
                Layout.preferredHeight: 50
                Layout.minimumWidth: 50
                font.pointSize: 10
                font.family: "Courier"
                Layout.fillWidth: true
                // onClicked:
                onClicked:{

                }
            }

            Switch {
                property string mappedVariable : ""
                id: startStopSw
                objectName: "startStopSw"
                text: directionSwitch
                display: AbstractButton.TextUnderIcon
//                font.pointSize: 10
                font.family: "Courier"
                Layout.preferredWidth: 80
                Layout.fillWidth: true
                width: 160
                indicator: Rectangle {
                     implicitWidth: 48
                     implicitHeight: 26
                     x: startStopSw.leftPadding
                     y: parent.height / 2 - height / 2
                     width: 90
                     height: 40
                     radius: 20
                     color: startStopSw.checked ? "#02231f" : "#ffffff"
                     border.color: startStopSw.checked ? "#17a81a" : "#cccccc"

                     Rectangle {
                         x: startStopSw.checked ? parent.width - width : 0
                         width: 40
                         height: 40
                         radius: 20
                         color: startStopSw.down ? "#cccccc" : "#ffffff"
                         border.color: startStopSw.checked ? (startStopSw.down ? "#17a81a" : "#21be2b") : "#999999"
                     }
                }

                contentItem: Text {
                    text: startStopSw.checked? "Start" : "Stop"
                    font: startStopSw.font
                    opacity: enabled ? 1.0 : 0.3
                    color: "#ebf5eb"
                    verticalAlignment: Text.AlignVCenter
//                    font.pointSize: 11
                    leftPadding: startStopSw.indicator.width + startStopSw.spacing
                }
                onToggled: {
                    udpworker.setTimerStatus(checked)
                }
            }
            TextField {
                id: speedTextInput
                objectName: "speedTextInput"
                width: 100
                height: 20
                color: "white"
                placeholderText:  qsTr("Enter speed!")
                font.pixelSize: 17
                Layout.preferredWidth: 120
                Layout.maximumWidth: 150
                Layout.minimumWidth: 80
                font.family: "Courier"
                Layout.fillWidth: true
                focus: false
                background: Rectangle{
                    anchors.fill: parent
                    radius: 20
                    color: "#02231f"
                    border.width: 1
                    border.color: "white"
                }

                onAccepted: {
                    udpworker.sendCommandToMCU(objectName, text)
                }
            }

            Switch {
                property string mappedVariable : ""
                id: directionSw
                objectName: "directionSw"
                width: 160
                // text: directionSwitch
                display: AbstractButton.TextUnderIcon
                indicator: Rectangle {
                    x: directionSw.leftPadding
                    y: parent.height / 2 - height / 2
                    width: 90
                    height: 40
                    color: directionSw.checked ? "#02231f" : "#ffffff"
                    radius: 20
                    border.color: directionSw.checked ? "#02231f" : "#cccccc"
                    Rectangle {
                        x: directionSw.checked ? parent.width - width : 0
                        width: 40
                        height: 40
                        color: directionSw.down ? "#cccccc" : "#ffffff"
                        radius: 20
                        border.color: directionSw.checked ? (directionSw.down ? "#17a81a" : "#21be2b") : "#999999"
                    }
                    implicitHeight: 26
                    implicitWidth: 48
                }
//                font.pointSize: 10
                Layout.preferredWidth: 80
                font.family: "Courier"
                contentItem: Text {
                    opacity: enabled ? 1.0 : 0.3
                    color: "#ebf5eb"
                    text: directionSw.checked ? "Forward" : "Backward"
                    verticalAlignment: Text.AlignVCenter
//                    font.pointSize: 11
                    font: directionSw.font
                    leftPadding: directionSw.indicator.width + directionSw.spacing
                }
                Layout.fillWidth: true
            }

            Rectangle {
                property string mappedVariable : ""
                id: connectionstatus
                objectName: "connectstatus"
                color: connected ? "lime" : "red"
                Layout.fillWidth: true
                Layout.maximumHeight: 60
                Layout.maximumWidth: 60
                Layout.minimumHeight: 40
                Layout.minimumWidth: 40
                Layout.preferredHeight: 50
                Layout.preferredWidth: 50
                radius:50

                Layout.rightMargin: 10
                Image {
                    id: connectionsIcon
                    anchors.fill: parent
                    source: connected ? "qrc:/images/images/svg_images/icons8-online-100.png" : "qrc:/images/images/svg_images/icons8-offline-100.png"
                    fillMode: Image.PreserveAspectFit
                    anchors.margins: 10
                }
            }
        }
    }

}
