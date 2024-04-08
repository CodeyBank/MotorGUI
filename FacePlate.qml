import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Popup {
    id: root
    width: 550
    height: 350
    // x: parent.x-width/2
    // y: parent.y -height/2
    anchors.centerIn: parent
    modal: true
    focus: true
    visible: false

    property alias intBind: roundButton
    property alias intTaglist : taglist
    property alias intUnit :units
    property alias intAlias: alias
    property alias intHeading: name

    Rectangle {
        id: rectangle
        color: "white"
        radius: 50
        anchors.fill: parent

        ColumnLayout {
            id: gridLayout
            anchors.fill: parent
            spacing: 10
            anchors.rightMargin: 20
            anchors.leftMargin: 20
            anchors.bottomMargin: 20
            anchors.topMargin: 20

            RowLayout{
                Layout.fillWidth: true
                Layout.fillHeight: true
                height: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Rectangle{
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 300
                    color: "grey"
                    Text {
                        id: name
                        text: parent.objectName
                        anchors.centerIn: parent
                        font.family: "Courier"
                    }
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.bottomMargin: 5

                }
            }

            RowLayout{
                Layout.fillWidth: true
                Layout.fillHeight: true

                Text {
                    id: text1
                    text: qsTr("Select variable")
                    verticalAlignment: Text.AlignVCenter
                    Layout.preferredWidth: 150
                    Layout.preferredHeight: 40
                    font.family: "Courier"
                    font.pixelSize: 16

                }
                // ComboBox{
                //     id:taglist
                //     leftPadding: 30
                //     Layout.preferredHeight: 40
                //     Layout.preferredWidth: 300
                //     Layout.fillHeight: false
                //     Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                //     anchors.topMargin: 10
                //     font.family: "Tahoma"
                //     displayText: "Select GUI Control Object"
                //     // model: udpworker.variablelist
                // }

                ComboBox {
                    id: taglist
                    width: parent.width * 0.80
                    height: 25
                    // model: udpworker.variablelist
                    leftPadding: 30
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 300
                    Layout.fillHeight: false
                    // Layout.fillWidth:
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    anchors.topMargin: 10
                    // anchors.horizontalCenter: parent.horizontalCenter
                    font.pointSize: 10
                    font.family: "Tahoma"
                    displayText: "Select GUI Control Object"

                    delegate: ItemDelegate {
                            width: taglist.width
                            contentItem: Text {
                                text: modelData
                                color: "#21be2b"
                                font: taglist.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: taglist.highlightedIndex === index
                        }

                        indicator: Canvas {
                            id: canvas
                            x: taglist.width - width - taglist.rightPadding
                            y: taglist.topPadding + (taglist.availableHeight - height) / 2
                            width: 12
                            height: 8
                            contextType: "2d"

                            Connections {
                                target: taglist
                                function onPressedChanged() { canvas.requestPaint(); }
                            }

                            onPaint: {
                                // context.reset();
                                // context.moveTo(0, 0);
                                // context.lineTo(width, 0);
                                // context.lineTo(width / 2, height);
                                // context.closePath();
                                // context.fillStyle = taglist.pressed ? "#17a81a" : "#21be2b";
                                // context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 0
                            rightPadding: taglist.indicator.width + taglist.spacing

                            text: taglist.displayText
                            font: taglist.font
                            color: taglist.pressed ? "black" : "black"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: taglist.pressed ? "#17a81a" : "#21be2b"
                            border.width: taglist.visualFocus ? 2 : 1
                            radius: 2
                        }

                        popup: Popup {
                            y: taglist.height - 1
                            width: taglist.width
                            implicitHeight: 150
                            padding: 1

                            contentItem: ListView {
                                clip: true
                                implicitHeight: contentHeight
                                model: taglist.popup.visible ? taglist.delegateModel : null
                                currentIndex: taglist.highlightedIndex

                                ScrollIndicator.vertical: ScrollIndicator { }
                            }

                            background: Rectangle {
                                border.color: "#21be2b"
                                radius: 2
                            }
                        }

                        onActivated: {
                            displayText = textAt(currentIndex)
                            console.log(displayText)

                        }
                }

            }

            RowLayout{
                Layout.fillWidth: true
                Layout.fillHeight: true

                Text {
                    id: text2
                    text: qsTr("Alias")

                    font.family: "Courier"
                    font.pixelSize: 16
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 150
                    verticalAlignment: Text.AlignVCenter
                }

                TextField {
                    id: alias
                    objectName: "alias"
                    color: "white"
                    placeholderText:  qsTr("Enter alias")
                    font.pixelSize: 17
                    Layout.preferredWidth: 300
                    Layout.preferredHeight: 40
                    font.family: "Courier"
                    focus: false
                    background: Rectangle{
                        anchors.fill: parent
                        radius: 20
                        color: "#02231f"
                        border.width: 1
                        border.color: "white"
                    }

                    onAccepted: {
                        // udpworker.sendCommandToMCU(objectName, text)
                    }
                }
            }

            RowLayout{
                Layout.fillWidth: true
                Layout.fillHeight: true
                Text {
                    id: text3
                    text: qsTr("Units")
                    font.family: "Courier"
                    font.pixelSize: 16
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 150
                    verticalAlignment: Text.AlignVCenter
                }

                TextField {
                    id: units
                    objectName: "units"
                    color: "white"
                    placeholderText:  qsTr("Enter units")
                    font.pixelSize: 17
                    Layout.preferredWidth: 300
                    Layout.preferredHeight: 40
                    font.family: "Courier"
                    focus: false
                    background: Rectangle{
                        anchors.fill: parent
                        radius: 20
                        color: "#02231f"
                        border.width: 1
                        border.color: "white"
                    }

                    onAccepted: {
                        // udpworker.sendCommandToMCU(objectName, text)
                    }
                }
        }


            RoundButton {
                id: roundButton
                text: "bind"
                font.family: "Courier"

                Layout.preferredHeight: 50
                icon.width: 17
                Layout.preferredWidth: 150
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                onClicked: {
                    root.focus = false
                    root.visible = false
                }
            }


        }


    }


}
