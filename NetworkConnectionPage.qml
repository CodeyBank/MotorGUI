import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2
// import Qt.labs.platform 1.1

Item {
    property alias intLocalComboBox : comboBox
    property alias connect:  roundButton1
    property alias disconnect: roundButton2

    // property alias intRemoteComboBox : comboBox1
    QtObject{

        id: internal
        function validatePort(port){
            if(port !==""){
                if(appmanager.isValidPort(port) ===false){
                    configdialog.text = "Invalid port"
                    configdialog.open()
                    remotePortField.clear()
                }
            }

        }

        function validateIPAddress(ip_addr){
            if(ip_addr.text !== ""){
                if(appmanager.isValidIPAddress(ip_addr.text) === false){
                    configdialog.text = "Invalid IP address"
                    configdialog.detailedText = "You must enter a valid IP address in the form xxx.xxx.xxx.xxx"
                    configdialog.open()
                    ip_addr.clear()

                }
            }
        }
    }


    Component.onCompleted: {
        //TODO fix situations where no settings were saved
        appmanager.loadSettings()

        localIPaddressField.text = appmanager.localIPAddress
        localPortField.text = appmanager.localPort

        remotePortField.text = appmanager.remotePort
        remoteIPAddressField.text = appmanager.remoteIPAddress
    }
    Rectangle {
        id: rectangle
        color: "#f5f5f5"
        anchors.fill: parent

        ColumnLayout {
            id: columnLayout
            anchors.fill: parent

            Rectangle {
                id: rectangle1
                width: 200
                height: 200
                color: "#ffffff"
                radius: 50
                Layout.topMargin: 20
                Layout.preferredHeight: parent.height * 0.70
                Layout.preferredWidth: parent.width * 0.90
                Layout.rowSpan: 1
                Layout.fillWidth: false
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

                RowLayout {
                    id: rowLayout
                    anchors.fill: parent
                    spacing: 0
                    anchors.rightMargin: 20
                    anchors.leftMargin: 20
                    anchors.bottomMargin: 20
                    anchors.topMargin: 20

                    ColumnLayout {
                        id: columnLayout1
                        width: 100
                        height: 100
                        spacing: 0
                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        Rectangle {
                            id: rectangle3
                            width: 200
                            height: 200
                            color: "#00000000"
                            Layout.preferredHeight: parent.height * 0.3
                            Layout.fillHeight: false
                            Layout.fillWidth: true

                            Image {
                                id: image
                                anchors.fill: parent
                                source: "qrc:/images/images/svg_images/computer.png"
                                fillMode: Image.PreserveAspectFit
                            }
                        }

                        Rectangle {
                            id: rectangle4
                            width: 200
                            height: 200
                            color: "#00000000"
                            Layout.rowSpan: 2
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            ColumnLayout {
                                id: columnLayout4
                                anchors.fill: parent
                                anchors.rightMargin: 10
                                anchors.leftMargin: 10
                                anchors.bottomMargin: 30
                                anchors.topMargin: 30

                                ComboBox {
                                    id: comboBox
                                    width: parent.width * 0.80
                                    height: 25
                                    // anchors.top: parent.top
                                    leftPadding: 30
                                    Layout.preferredHeight: 40
                                    Layout.fillHeight: false
                                    Layout.fillWidth: true
                                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                    anchors.topMargin: 10
                                    // anchors.horizontalCenter: parent.horizontalCenter
                                    font.pointSize: 10
                                    font.family: "Tahoma"
                                    displayText: "Select interface"

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
                                            implicitHeight: contentItem.implicitHeight/3
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
                                            var ip = appmanager.getIpAddressByInterfaceName(displayText)
                                            localIPaddressField.text = ip


                                        }
                                }

                                RowLayout {
                                    id: rowLayout1
                                    height: 100
                                    // anchors.left: parent.left
                                    // anchors.right: parent.right
                                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                    Layout.fillHeight: true
                                    Layout.fillWidth: true
                                    anchors.leftMargin: 0
                                    anchors.rightMargin: 0

                                    Text {
                                        id: text1
                                        text: qsTr("IP Address")
                                        font.pixelSize: 12
                                        verticalAlignment: Text.AlignVCenter
                                        Layout.fillWidth: true
                                        Layout.preferredHeight: 40
                                        Layout.preferredWidth: 70
                                    }
                                    TextField {
                                        id: localIPaddressField
                                        width: 80
                                        height: 25
                                        leftPadding: 5
                                        topPadding: 10
                                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                        Layout.fillWidth: true
                                        Layout.preferredWidth: 150
                                        Layout.preferredHeight: 40
                                        Layout.topMargin: 15
                                        placeholderText: qsTr("Local IP address")
                                        onFocusChanged: internal.validateIPAddress(localIPaddressField)

                                    }
                                }

                                RowLayout {
                                    id: rowLayout2
                                    height: 100
                                    // anchors.left: parent.left
                                    // anchors.right: parent.right
                                    Layout.fillWidth: true
                                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                    anchors.rightMargin: 0
                                    Text {
                                        id: text2
                                        text: qsTr("Local Port")
                                        font.pixelSize: 12
                                        verticalAlignment: Text.AlignVCenter
                                        Layout.fillWidth: true
                                        Layout.preferredWidth: 70
                                        Layout.preferredHeight: 40
                                    }

                                    TextField {
                                        id: localPortField
                                        width: 80
                                        height: 25
                                        Layout.fillWidth: true
                                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                        leftPadding: 5
                                        Layout.topMargin: 15
                                        Layout.preferredWidth: 150
                                        topPadding: 10
                                        Layout.preferredHeight: 40
                                        placeholderText: qsTr("Local Port")
                                        validator: RegularExpressionValidator{
                                            regularExpression: /^(0|6[0-5][0-5][0-3][0-5]|[1-5][0-9][0-9][0-9][0-9]|[1-9][0-9]{0,3})$/
                                        }
                                    }
                                    Layout.fillHeight: true
                                    // anchors.leftMargin: 0
                                }
                            }
                        }
                    }

                    ColumnLayout {
                        id: columnLayout2
                        width: 100
                        height: 100
                        spacing: 0

                        Rectangle {
                            id: rectangle6
                            width: 200
                            height: 200
                            color: "#00000000"
                            Layout.preferredHeight: parent.height * 0.30
                            z: 1
                            Layout.preferredWidth: 50
                            Layout.fillHeight: false
                            Layout.fillWidth: false

                            Image {
                                id: image1
                                anchors.fill: parent
                                source: "qrc:/images/images/svg_images/exchange.png"
                                rotation: 0
                                fillMode: Image.PreserveAspectFit
                            }
                        }

                        Rectangle {
                            id: rectangle7
                            width: 200
                            height: 200
                            color: "#00000000"
                            Layout.preferredWidth: 50
                            Layout.fillHeight: true
                            Layout.fillWidth: false

                            Rectangle {
                                id: rectangle5
                                width: 1
                                height: parent.height*0.95
                                color: "#031a09"

                                anchors.bottom : parent.bottom
                                anchors.horizontalCenter: parent.horizontalCenter
                            }
                        }
                    }

                    ColumnLayout {
                        id: columnLayout3
                        width: 100
                        height: 100
                        spacing: 0

                        Rectangle {
                            id: rectangle9
                            width: 200
                            height: 200
                            color: "#00000000"
                            Layout.preferredHeight: parent.height * 0.30
                            Layout.fillHeight: false
                            Layout.fillWidth: true

                            Image {
                                id: image2
                                anchors.fill: parent
                                source: "qrc:/images/images/svg_images/computer.png"
                                fillMode: Image.PreserveAspectFit
                            }
                        }

                        Rectangle {
                            id: rectangle10
                            width: 200
                            height: 200
                            color: "#00000000"
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            ColumnLayout {
                                id: columnLayout5
                                anchors.fill: parent
                                anchors.rightMargin: 10
                                anchors.topMargin: 30
                                // ComboBox {
                                //     id: comboBox1
                                //     width: parent.width * 0.80
                                //     height: 25
                                //     // anchors.top: parent.top
                                //     Layout.fillWidth: true
                                //     Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                //     displayText: "Select interface"
                                //     leftPadding: 30
                                //     Layout.topMargin: 10
                                //     font.pointSize: 10
                                //     Layout.preferredHeight: 40
                                //     font.family: "Tahoma"
                                //     Layout.fillHeight: false
                                //     // anchors.horizontalCenter: parent.horizontalCenter
                                // }

                                RowLayout {
                                    id: rowLayout3
                                    height: 100
                                    // anchors.left: parent.left
                                    // anchors.right: parent.right
                                    Layout.fillWidth: true
                                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                    anchors.rightMargin: 0
                                    Text {
                                        id: text3
                                        text: qsTr("Remote IP Address")
                                        font.pixelSize: 12
                                        verticalAlignment: Text.AlignVCenter
                                        Layout.fillWidth: true
                                        Layout.preferredWidth: 70
                                        Layout.preferredHeight: 40
                                    }

                                    TextField {
                                        id: remoteIPAddressField
                                        width: 80
                                        height: 25
                                        Layout.fillWidth: true
                                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                        leftPadding: 5
                                        Layout.topMargin: 15
                                        Layout.preferredWidth: 150
                                        topPadding: 10
                                        Layout.preferredHeight: 40
                                        placeholderText: qsTr("Remote IP Address")
                                        onFocusChanged: internal.validateIPAddress(remoteIPAddressField)
                                    }
                                    Layout.fillHeight: true
                                    // anchors.leftMargin: 0
                                }

                                RowLayout {
                                    id: rowLayout4
                                    height: 100
                                    // anchors.left: parent.left
                                    // anchors.right: parent.right
                                    Layout.fillWidth: true
                                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                    anchors.rightMargin: 0
                                    Text {
                                        id: text4
                                        text: qsTr("Remote Port")
                                        font.pixelSize: 12
                                        verticalAlignment: Text.AlignVCenter
                                        Layout.fillWidth: true
                                        Layout.preferredWidth: 70
                                        Layout.preferredHeight: 40
                                    }

                                    TextField {
                                        id: remotePortField
                                        width: 80
                                        height: 25
                                        Layout.fillWidth: true
                                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                        leftPadding: 5
                                        anchors.topMargin: 15
                                        Layout.preferredWidth: 150
                                        topPadding: 10
                                        Layout.preferredHeight: 40
                                        placeholderText: qsTr("Remote Port")

                                        validator: RegularExpressionValidator{
                                            regularExpression: /^(0|6[0-5][0-5][0-3][0-5]|[1-5][0-9][0-9][0-9][0-9]|[1-9][0-9]{0,3})$/

                                        }
                                        onFocusChanged: {
                                            internal.validatePort(remotePortField.text)
                                        }
                                    }
                                    Layout.fillHeight: true
                                    anchors.leftMargin: 0
                                }
                                anchors.leftMargin: 10
                                anchors.bottomMargin: 30
                            }
                        }
                    }

                }
            }


            MessageDialog{

                id: configdialog
                standardButtons:  MessageDialog.Ok
                text: "Invalid port"

            }

            Rectangle {
                id: rectangle2
                color: "#ffffff"
                radius: 20
                Layout.bottomMargin: 20
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.preferredHeight: rectangle.height *0.15
                Layout.preferredWidth: rectangle1.width
                Layout.fillHeight: false
                Layout.fillWidth: false

                RowLayout {
                    id: rowLayout5
                    height: 100
                    anchors.verticalCenter: parent.verticalCenter
                    // anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.leftMargin: parent.width * 0.4
                    anchors.rightMargin: 50

                    RoundButton {
                        id: roundButton
                        text: "Test "
                        Layout.preferredWidth: 100
                        onClicked: {
                            appmanager.testRemoteDevice(remoteIPAddressField.text)
                        }
                    }

                    RoundButton {
                        id: roundButton1
                        text: "Connect"
                        Layout.preferredWidth: 100
                        enabled: false
                        onClicked: {
                            // send all the data on the gui to the back end
                            appmanager.localIPAddress = localIPaddressField.text
                            appmanager.localPort = localPortField.text
                            appmanager.remoteIPAddress = remoteIPAddressField.text
                            appmanager.remotePort = remotePortField.text

                            udpworker.localIPAddress = localIPaddressField.text
                            udpworker.localPort = localPortField.text
                            udpworker.remoteIPAddress = remoteIPAddressField.text
                            udpworker.remotePort = remotePortField.text
                            udpworker.start()
                            appmanager.saveSettings()
                            if(appmanager.heartbeat){
                                maintopbar.connection_status = "Connected to " +appmanager.remoteIPAddress +
                                                                " via port: " + appmanager.remotePort
                                networkPage.connect.enabled = false
                                networkPage.disconnect.enabled = true
                            }else{
                                maintopbar.connection_status = "Reconnecting ..."
                            }
                        }
                    }

                    RoundButton {
                        id: roundButton2
                        text: "Disconnect"
                        Layout.preferredWidth: 100
                        Layout.fillWidth: false
                        enabled: false
                        onClicked: {
                            udpworker.stop()
                            // memorymodel.clear()
                            maintopbar.connection_status = "No active connections"
                            networkPage.disconnect.enabled = false
                            networkPage.connect.enabled = true
                            appmanager.disconnect()
                        }
                    }
                }
            }
        }
    }

}


