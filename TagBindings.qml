import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 1.4 as C14


Item {
    id:root
    property alias varlist : tagComboBox
    property alias guiObjComboBox : guiObjComboBox
    property alias bind : roundButton
    property alias write :writeRadioButton
    property alias read :readbtn
    property alias unused : unusedRadioBtn
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
                        model:bindingmodel
                        C14.TableViewColumn {
                            title: "TagName"
                            role: "tag"
                            width: listviewContainer.width/3
                        }
                        C14.TableViewColumn {
                            title: "GUI Object id"
                            role: "name"
                            width: listviewContainer.width/3
                        }
                        C14.TableViewColumn {
                            title: "Type"
                            role: "readwrite"
                            width: listviewContainer.width/3
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
                        id: guiObjComboBox
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
                                width: guiObjComboBox.width
                                contentItem: Text {
                                    text: modelData
                                    color: "#21be2b"
                                    font: guiObjComboBox.font
                                    elide: Text.ElideRight
                                    verticalAlignment: Text.AlignVCenter
                                }
                                highlighted: guiObjComboBox.highlightedIndex === index
                            }

                            indicator: Canvas {
                                id: canvas
                                x: guiObjComboBox.width - width - guiObjComboBox.rightPadding
                                y: guiObjComboBox.topPadding + (guiObjComboBox.availableHeight - height) / 2
                                width: 12
                                height: 8
                                contextType: "2d"

                                Connections {
                                    target: guiObjComboBox
                                    function onPressedChanged() { canvas.requestPaint(); }
                                }

                                onPaint: {
                                    context.reset();
                                    context.moveTo(0, 0);
                                    context.lineTo(width, 0);
                                    context.lineTo(width / 2, height);
                                    context.closePath();
                                    context.fillStyle = guiObjComboBox.pressed ? "#17a81a" : "#21be2b";
                                    context.fill();
                                }
                            }

                            contentItem: Text {
                                leftPadding: 0
                                rightPadding: guiObjComboBox.indicator.width + guiObjComboBox.spacing

                                text: guiObjComboBox.displayText
                                font: guiObjComboBox.font
                                color: guiObjComboBox.pressed ? "black" : "black"
                                verticalAlignment: Text.AlignVCenter
                                elide: Text.ElideRight
                            }

                            background: Rectangle {
                                implicitWidth: 120
                                implicitHeight: 40
                                border.color: guiObjComboBox.pressed ? "#17a81a" : "#21be2b"
                                border.width: guiObjComboBox.visualFocus ? 2 : 1
                                radius: 2
                            }

                            popup: Popup {
                                y: guiObjComboBox.height - 1
                                width: guiObjComboBox.width
                                implicitHeight: 150
                                padding: 1

                                contentItem: ListView {
                                    clip: true
                                    implicitHeight: contentHeight
                                    model: guiObjComboBox.popup.visible ? guiObjComboBox.delegateModel : null
                                    currentIndex: guiObjComboBox.highlightedIndex

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
                            id: unusedRadioBtn
                            text: qsTr("Unused")
                            Layout.preferredWidth: 100
                            Layout.preferredHeight: 30
                            topPadding: -10
                            display: AbstractButton.TextBesideIcon
                            Layout.fillWidth: true
                        }

                        RadioButton {
                            id: writeRadioButton
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
