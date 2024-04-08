import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.15


Item {
    Row{
        spacing: 10
        Rectangle{
            width: base.width/3
            height:base.height
            border.width: 1
            border.color: "grey"
            radius: 20

            anchors.topMargin: 20

            ColumnLayout{
                spacing: 10

                Dial{

                    Layout.preferredWidth:  60
                    Layout.preferredHeight: 60
                    // Layout.leftMargin:60
                    Layout.alignment: Qt.AlignCenter
                    Layout.topMargin: 2
                }
                Slider{
                    // Layout.preferredWidth:  200
                    Layout.preferredHeight: 60
                    Layout.leftMargin:60
                    Layout.alignment: Qt.AlignCenter
                }
                Item{
                    Layout.leftMargin: 60
                    Layout.alignment: Qt.AlignCenter
                    RowLayout{
                        TextField{
                            placeholderText: qsTr("Enter Speed")
                            Layout.preferredWidth:  100
                            Layout.preferredHeight: 30
                        }
                        Button{
                           text: "Send"
                           Layout.preferredWidth:  60
                           Layout.preferredHeight: 30
                        }
                    }
                }
            }
        }
        Rectangle{
            width: base.width/3
            height:base.height
            SpeedGuage{

                anchors.fill: parent
                // anchors.margins: 50
                anchors.bottomMargin: 50
                // Layout.alignment: Qt.AlignHCenter
            }
            Text{
                text: "Speed-RPM"
            }
        }
        Rectangle{
            width: base.width/3
            height:base.height
            color: "grey"
            Text {
                id: rightitem
                text: qsTr("On/Off/Direction Controls")
                anchors.centerIn: parent
            }
        }
    }
}
