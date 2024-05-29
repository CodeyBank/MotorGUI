import QtQuick 2.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.15
import QtQuick.Dialogs 1.0
import QtQuick.Window 2.12

Item {

    property string status: "No active connections"
    property string current_page_topbar: "| OVERVIEW"
    property alias intbtn : internalbtn
    property alias intclose : btnClose
    property alias intmaxrestore: btnMaximizeRestore
    property alias intminimize: btnMinimize
    property alias connection_status: labelTopInfo.text

    Rectangle {
        id: topBar
        height: 60
        color:  "#343644"
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0

        ToggleBtn {
            id:internalbtn
            // onClicked: animationMenu.running = true
            btnColorClicked: "#012721"
            btnColorMouseOver: "#038874"
            btnColorDefault: "#02312a"
        }

        Rectangle {

            id: rectangle
            y: 21
            height: 30
            color: "#d3d3d3"
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 70
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0

            Label {
                id: labelTopInfo
                color: "#707d99"
                text: "No active connections"
                font.family: "Montserrat"
                font.pointSize: 10
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                anchors.right: rectangle.right
                anchors.rightMargin: 300
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.top: parent.top
                anchors.topMargin: 0
            }
            // NetworkConnectBtn{
            //     width: 100
            //     height: 25
            //     anchors.right: labelRightInfo.right
            //     anchors.top: rectangle.top
            //     anchors.rightMargin: 10
            //     anchors.topMargin: 5
            //     btnColorClicked: "#012721"
            //     btnColorMouseOver: "#038874"
            //     btnColorDefault: "transparent"
            // }

        }

        Rectangle {
            id: titleBar
            width: 200
            height: 35
            color: "#013b32"
            anchors.right: parent.right
            anchors.rightMargin: 105
            anchors.left: parent.left
            anchors.leftMargin: 70
            anchors.top: parent.top
            anchors.topMargin: 0


            Image {
                id: iconApp
                width: 28
                anchors.left: parent.left
                anchors.leftMargin: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.top: parent.top
                anchors.topMargin: 0
                source: "qrc:/images/images/svg_images/icon_app_top.svg"
                fillMode: Image.PreserveAspectFit
            }

            Label {
                id: labelTitle
                color: "#ffffff"
                text: qsTr("FUTURE MOTOR CONTROL TOOL")
                font.family: "Montserrat"
                font.pointSize: 10
                verticalAlignment: Text.AlignVCenter
                styleColor: "#fff7f7"
                anchors.left: iconApp.right
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.top: parent.top
                anchors.leftMargin: 5

                MouseArea{
                    id: maintopbarresize
                    anchors.fill: parent

                    onDoubleClicked: {
                        internal.maximizeRestore()
                        console.log("Double clicked")
                    }

                }
            }
        }

        Row {
            id: row
            x: 905
            width: 105
            height: 35
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0

            TopBarBtn {
                id: btnMinimize
                btnColorClicked: "#012721"
                btnColorMouseOver: "#038874"
                btnColorDefault: "#02312a"
                onClicked: {
                    mainwindow.showMinimized()
                    internal.restoreMargins()
                }
            }

            TopBarBtn {
                id: btnMaximizeRestore
                btnIconSource: "qrc:/images/images/svg_images/maximize_icon.svg"
                btnColorClicked: "#012721"
                btnColorMouseOver: "#038874"
                btnColorDefault: "#02312a"
                onClicked: internal.maximizeRestore()
            }

            TopBarBtn {
                id: btnClose
                btnIconSource: "qrc:/images/images/svg_images/close_icon.svg"
                btnColorClicked: "#760310"
                btnColorMouseOver: "#ff061f"
                btnColorDefault: "#02312a"
                onClicked: mainwindow.close()
            }
        }
    }


}
