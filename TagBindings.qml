import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 1.4 as C14


Item {
    id:root
    property alias varlist : tagComboBox
    property alias objList : comboBox
    property alias bind : roundButton
    property alias write :radioButton4
    property alias read :readbtn

    Rectangle {
        id: rectangle
        color: "#ebebeb"
        anchors.fill: parent

        ColumnLayout {
            id: columnLayout
            anchors.fill: parent
            spacing: 15
            anchors.bottomMargin: parent.height * 0.05
            anchors.topMargin: parent.height * 0.05
            anchors.rightMargin: parent.width * 0.05
            anchors.leftMargin: parent.width * 0.05

            Rectangle {
                id: listviewContainer
                color: "white"
                radius: 10
                Layout.fillHeight: true
                Layout.fillWidth: true

                C14.TableView {

                        anchors.fill: parent
                        anchors.margins: 10
                        model:memorymodel
                        C14.TableViewColumn {
                            title: "TagName"
                            role: "name"
                        }
                        C14.TableViewColumn {
                            title: "GUI Object id"
                            role: "objid"
                        }
                        C14.TableViewColumn {
                            title: "Type"
                            role: "type"
                        }

                   }

            }

            Rectangle {
                id: configSettingContrainer
                color: "white"
                radius: 10
                Layout.preferredHeight: 100
                Layout.fillWidth: true
                // Layout.fillHeight: true

                RowLayout {
                    id: rowLayout
                    anchors.fill: parent
                    spacing: 5
                    anchors.rightMargin: parent.width * 0.1
                    anchors.leftMargin: parent.width * 0.1

                    ComboBox {
                        id: comboBox
                        width: parent.width * 0.80
                        height: 25
                        // anchors.top: parent.top
                        leftPadding: 30
                        Layout.preferredHeight: 55
                        Layout.preferredWidth: parent.width * 0.3
                        Layout.fillHeight: false
                        // Layout.fillWidth: true
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        anchors.topMargin: 10
                        // anchors.horizontalCenter: parent.horizontalCenter
                        font.pointSize: 10
                        font.family: "Tahoma"
                        displayText: "Select GUI Control Object"

                        delegate: ItemDelegate {
                                width: comboBox.width
                                contentItem: Text {
                                    text: modelData
                                    color: "#21be2b"
                                    font: comboBox.font
                                    elide: Text.ElideRight
                                    verticalAlignment: Text.AlignVCenter
                                }
                                highlighted: comboBox.highlightedIndex === index
                            }

                            indicator: Canvas {
                                id: canvas
                                x: comboBox.width - width - comboBox.rightPadding
                                y: comboBox.topPadding + (comboBox.availableHeight - height) / 2
                                width: 12
                                height: 8
                                contextType: "2d"

                                Connections {
                                    target: comboBox
                                    function onPressedChanged() { canvas.requestPaint(); }
                                }

                                onPaint: {
                                    context.reset();
                                    context.moveTo(0, 0);
                                    context.lineTo(width, 0);
                                    context.lineTo(width / 2, height);
                                    context.closePath();
                                    context.fillStyle = comboBox.pressed ? "#17a81a" : "#21be2b";
                                    context.fill();
                                }
                            }

                            contentItem: Text {
                                leftPadding: 0
                                rightPadding: comboBox.indicator.width + comboBox.spacing

                                text: comboBox.displayText
                                font: comboBox.font
                                color: comboBox.pressed ? "black" : "black"
                                verticalAlignment: Text.AlignVCenter
                                elide: Text.ElideRight
                            }

                            background: Rectangle {
                                implicitWidth: 120
                                implicitHeight: 40
                                border.color: comboBox.pressed ? "#17a81a" : "#21be2b"
                                border.width: comboBox.visualFocus ? 2 : 1
                                radius: 2
                            }

                            popup: Popup {
                                y: comboBox.height - 1
                                width: comboBox.width
                                implicitHeight: 150
                                padding: 1

                                contentItem: ListView {
                                    clip: true
                                    implicitHeight: contentHeight
                                    model: comboBox.popup.visible ? comboBox.delegateModel : null
                                    currentIndex: comboBox.highlightedIndex

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

                    ComboBox {
                        id: tagComboBox
                        width: parent.width * 0.80
                        height: 25
                        // anchors.top: parent.top
                        leftPadding: 30
                        Layout.preferredHeight: 55
                        Layout.preferredWidth: parent.width * 0.3
                        Layout.fillHeight: false
                        // Layout.fillWidth: true
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        anchors.topMargin: 10
                        // anchors.horizontalCenter: parent.horizontalCenter
                        font.pointSize: 10
                        font.family: "Tahoma"
                        displayText: "Select Tag"
                        // model: udpworker.

                        delegate: ItemDelegate {
                                width: tagComboBox.width
                                contentItem: Text {
                                    text: modelData
                                    color: "#21be2b"
                                    font: tagComboBox.font
                                    elide: Text.ElideRight
                                    verticalAlignment: Text.AlignVCenter
                                }
                                highlighted: tagComboBox.highlightedIndex === index
                            }

                            indicator: Canvas {
                                id: canvas2
                                x: tagComboBox.width - width - tagComboBox.rightPadding
                                y: tagComboBox.topPadding + (tagComboBox.availableHeight - height) / 2
                                width: 12
                                height: 8
                                contextType: "2d"

                                Connections {
                                    target: tagComboBox
                                    function onPressedChanged() { canvas2.requestPaint(); }
                                }

                                onPaint: {
                                    context.reset();
                                    context.moveTo(0, 0);
                                    context.lineTo(width, 0);
                                    context.lineTo(width / 2, height);
                                    context.closePath();
                                    context.fillStyle = tagComboBox.pressed ? "#17a81a" : "#21be2b";
                                    context.fill();
                                }
                            }

                            contentItem: Text {
                                leftPadding: 0
                                rightPadding: tagComboBox.indicator.width + tagComboBox.spacing

                                text: tagComboBox.displayText
                                font: tagComboBox.font
                                color: tagComboBox.pressed ? "black" : "black"
                                verticalAlignment: Text.AlignVCenter
                                elide: Text.ElideRight
                            }

                            background: Rectangle {
                                implicitWidth: 120
                                implicitHeight: 40
                                border.color: tagComboBox.pressed ? "#17a81a" : "#21be2b"
                                border.width: tagComboBox.visualFocus ? 2 : 1
                                radius: 2
                            }

                            popup: Popup {
                                y: tagComboBox.height - 1
                                width: tagComboBox.width
                                implicitHeight: contentItem.implicitHeight/3
                                padding: 1

                                contentItem: ListView {
                                    clip: true
                                    implicitHeight: contentHeight
                                    model: tagComboBox.popup.visible ? tagComboBox.delegateModel : null
                                    currentIndex: tagComboBox.highlightedIndex

                                    ScrollIndicator.vertical: ScrollIndicator { }
                                }

                                background: Rectangle {
                                    border.color: "#21be2b"
                                    radius: 2
                                }
                            }

                            onActivated: {
                                displayText = textAt(currentIndex)
                                // tagComboBox.ctext = displayText
                            }
                    }


                    GridLayout {
                        id: columnLayout1
                        Layout.leftMargin: 10
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        Layout.topMargin: 9
                        // spacing: 0
                        columns: 2
                        rows: 2

                        RadioButton {
                            id: readbtn
                            text: qsTr("Read")
                            Layout.preferredWidth: 100
                            Layout.preferredHeight: 30
                            Layout.fillHeight: false
                            topPadding: -10
                            baselineOffset: 9
                            layer.mipmap: false
                            topInset: 0
                            Layout.fillWidth: true
                        }

                        RadioButton {
                            id: radioButton1
                            text: qsTr("Load")
                            Layout.preferredWidth: 100
                            Layout.preferredHeight: 30
                            topPadding: -10
                            display: AbstractButton.TextBesideIcon
                            Layout.fillWidth: true
                        }

                        RadioButton {
                            id: radioButton2
                            text: qsTr("Unused")
                            Layout.preferredWidth: 100
                            Layout.preferredHeight: 30
                            topPadding: -10
                            display: AbstractButton.TextBesideIcon
                            Layout.fillWidth: true
                        }

                        RadioButton {
                            id: radioButton4
                            text: qsTr("Write")
                            Layout.preferredWidth: 100
                            Layout.preferredHeight: 30
                            topPadding: -10
                            display: AbstractButton.TextBesideIcon
                            Layout.fillWidth: true
                        }

                    }

                    RoundButton {
                        id: roundButton
                        text: "bind"
                        highlighted: true
                        Layout.preferredWidth: 100
                        Layout.preferredHeight: 50


                    }
                }
            }
        }
    }

}
