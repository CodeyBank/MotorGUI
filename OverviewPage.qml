import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
// import QtWebView 1.0
Item {
    Rectangle{
        anchors.fill: parent
        color: "#ffffff"
        anchors.margins: 10
        radius: 50
        clip: true

        RowLayout {
            id: rowLayout
            anchors.fill: parent
            anchors.bottomMargin: 20
            anchors.leftMargin: 20
            anchors.rightMargin: 20


            Rectangle {
                id: rectangle
                width: 200
                height: 200
                color: "#ffffff"
                Layout.topMargin: 22
                Layout.margins: 25
                Layout.fillHeight: true
                Layout.fillWidth: true

                ColumnLayout {
                    id: columnLayout
                    anchors.fill: parent
                    anchors.topMargin: 15

                    Rectangle {
                        id: rectangle1
                        width: 200
                        height: 200
//                        color: "white"
                        radius: 10
                        Layout.leftMargin: 10
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50
                        Layout.fillWidth: true
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

                        gradient: Gradient{
                            GradientStop {position: 0.0; color: "#025346"}
                            GradientStop {position: 0.8; color: "#011512"}
                        }

                        Label {
                            id: label
                            text: qsTr("Application Concept")
                            anchors.left: parent.left
                            anchors.right: parent.right
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            font.family: "Courier"
                            font.pointSize: 16
                            anchors.topMargin: 0
                            anchors.bottomMargin: 0
                            anchors.rightMargin: 0
                            anchors.leftMargin: 0
                            color: "White"
                            font.bold: true

                        }
                    }

                    TextArea {
                        id: textArea
                        text: "\nA position and speed estimation method without position transducer is applied for drives with Permanent Magnet Synchronous Motor (PMSM). By integrating methods, i.e. using a speed reference for zero speed startup and low speed acceleration, and back-EMF for mid-high speed operation, the rotor position can be estimated and controlled over the full speed range. In order to achieve correct operation from zero speed, the two techniques are combined with a crossover function based on the speed reference."
                        verticalAlignment: Text.AlignVCenter
                        wrapMode: Text.WordWrap
                        font.pointSize: 13
                        font.family: "Courier"
                        Layout.preferredWidth: parent.width * 0.60
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        placeholderText: qsTr("Text Area")
                    }
                }
            }

            Rectangle{
                id: rectangle2
                Layout.preferredWidth: 300
                Layout.fillWidth: true
                Layout.fillHeight: true

                color: "#00000000"
                Image {
                    id: image
                    width: 150
                    height: 150
                    anchors.fill:parent
                    source: "qrc:/images/images/svg_images/speedfocwolswbemf.gif"
                    anchors.horizontalCenter: parent.horizontalCenter
                    fillMode: Image.PreserveAspectFit
                }

            }

        }

    }
}
