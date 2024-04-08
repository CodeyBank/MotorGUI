import QtQuick 2.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.15
import QtQuick.Dialogs 1.0
import QtQuick.Layouts 1.15

Item {
    Rectangle {
        id: bottomCredits
        color: "#282c34"
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: sidebar.right
        anchors.leftMargin: 1
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: contentPages.bottom
        anchors.topMargin: 0

        Label {
            id: credits
            color: "#707d99"
            text: qsTr("Message: ")
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.rightMargin: 30
            anchors.bottom: parent.bottom
            font.family: "Montserrat"
            verticalAlignment: Text.AlignVCenter
            anchors.topMargin: 0
            font.pointSize: 10
            horizontalAlignment: Text.AlignLeft
            anchors.bottomMargin: 0
            anchors.right: parent.right
            anchors.leftMargin: 10
        }
    }

}
