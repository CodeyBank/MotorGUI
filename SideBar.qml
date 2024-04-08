import QtQuick 2.0
import QtQuick.Dialogs 1.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.15

Item {
    property alias animate: animationMenu
    property alias intwidth: leftMenu.width

    property alias intBtnPlot : btnPlot
    property alias intBtnConfig : btnConfig
    property alias intBtnHome : btnHome
    property alias intBtnSettings: btnSettings
    property alias intBtnTagTable: btnTagTable

    Rectangle {
        id: leftMenu
        width: 70
        // color: "#2b2c31"
        border.color: "#00000000"
        border.width: 1
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0

        gradient: Gradient{
            GradientStop {position: 0.0; color: "#025346"}
            GradientStop {position: 0.8; color: "#011512"}
        }


        PropertyAnimation {
            id: animationMenu
            target: leftMenu
            property: "width"
            to: if (leftMenu.width === 70)
                    return 200
                else
                    return 70
            duration: 500
            easing.type: Easing.OutBounce
        }

        Column {
            id: column
            width: 250
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 90
            anchors.top: parent.top
            anchors.topMargin: 0

            LefMenuBtn {

                id: btnHome
                width: leftMenu.width
                height: 60
                text: qsTr("Overview")
                display: AbstractButton.TextOnly
                isActiveMenu: true
                btnColorClicked: "#012721"
                btnColorMouseOver: "#038874"
                btnColorDefault: "transparent"
                btnIconSource: "qrc:/images/images/svg_images/home_icon.svg"
                onClicked: {
                    btnHome.isActiveMenu = true
                    btnPlot.isActiveMenu = false
                    btnConfig.isActiveMenu = false
                    btnSettings.isActiveMenu = false
                    btnTagTable.isActiveMenu=false
                    // stackView.push(Qt.resolvedUrl(
                    //                    "pages/homePage.qml"))
                    //pagesView.setSource("pages/homePage.qml")
                }
            }

            LefMenuBtn {
                id: btnTagTable
                width: leftMenu.width
                height: 60
                text: qsTr("Configure")
                btnIconSource: "qrc:/images/images/svg_images/icons8-database-administrator-48.png"
                isActiveMenu: false
                display: AbstractButton.TextOnly
                btnColorClicked: "#012721"
                btnColorMouseOver: "#038874"
                btnColorDefault: "transparent"

                onClicked: {
                    btnHome.isActiveMenu = false
                    btnConfig.isActiveMenu = false
                    btnPlot.isActiveMenu = false
                    btnSettings.isActiveMenu = false
                    btnTagTable.isActiveMenu = true
                    // StackView.currentItem =
                }
            }

            LefMenuBtn {
                id: btnPlot
                width: leftMenu.width
                height: 60
                text: qsTr("Plots")
                btnIconSource: "qrc:/images/images/svg_images/icons8-plot-100.png"
                isActiveMenu: false
                display: AbstractButton.TextOnly
                btnColorClicked: "#012721"
                btnColorMouseOver: "#038874"
                btnColorDefault: "transparent"
                onClicked: {
                    btnHome.isActiveMenu = false
                    btnConfig.isActiveMenu = false
                    btnPlot.isActiveMenu = true
                    btnSettings.isActiveMenu = false
                     btnTagTable.isActiveMenu=false
                    // stackView.push(Qt.resolvedUrl("pages/settingsPage.qml"))
                    //pagesView.setSource("pages/settingsPage.qml")
                }
            }

            LefMenuBtn {
                id: btnConfig
                width: leftMenu.width
                height: 60
                text: qsTr("Configure")
                btnIconSource: "qrc:/images/images/svg_images/icons8-tools-50.png"
                isActiveMenu: false
                display: AbstractButton.TextOnly
                btnColorClicked: "#012721"
                btnColorMouseOver: "#038874"
                btnColorDefault: "transparent"

                onClicked: {
                    btnHome.isActiveMenu = false
                    btnConfig.isActiveMenu = true
                    btnPlot.isActiveMenu = false
                    btnSettings.isActiveMenu = false
                     btnTagTable.isActiveMenu=false
                    // StackView.currentItem =
                }
            }


        }
    }

    LefMenuBtn {
        id: btnSettings
        x: 0
        y: 180
        width: leftMenu.width
        height: 60
        text: qsTr("Settings")
        btnIconSource: "qrc:/images/images/svg_images/settings_icon.svg"
        clip: true
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 25
        isActiveMenu: false
        display: AbstractButton.TextOnly
        btnColorClicked: "#012721"
        btnColorMouseOver: "#038874"
        btnColorDefault: "transparent"

        onClicked: {
            btnHome.isActiveMenu = false
            btnConfig.isActiveMenu = false
            btnPlot.isActiveMenu = false
            btnSettings.isActiveMenu = true
            // stackView.push(Qt.resolvedUrl("pages/settingsPage.qml"))
            //pagesView.setSource("pages/settingsPage.qml")
        }
    }
}
