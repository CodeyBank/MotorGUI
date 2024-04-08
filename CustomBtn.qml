import QtQuick 2.15

Item {
    property color btncolor: "#5155B8"
    property color hovercolor: "#7D7FCA"
    property color hoverexitcolor: "#5155B8"
    property color clickcolor: "magenta"
    property color texthovercolor: "blue"
    property color textcolor: "black"
    property string text: "button"
    property alias rectbut: buttonrect
    property alias area: btnmousearea
    property int radius :0

    width: 50
    height: 50
    id: root

    Rectangle{
        id: buttonrect
        anchors.fill: parent
        radius: radius
        color: root.btncolor

        Text{
            id: btntext
            text:root.text
            color: "black"
            anchors.centerIn: buttonrect
            font.bold: false
        }

        MouseArea{
            id:btnmousearea
            anchors.fill: parent
            hoverEnabled: true
            onEntered: buttonrect.color = hovercolor
            onExited: buttonrect.color = btncolor
            onPressed: {
                btntext.color = root.texthovercolor
                buttonrect.color = clickcolor
            }
            onReleased: {
                btntext.color = root.textcolor
                buttonrect.color = btncolor
            }
        }
    }

}
