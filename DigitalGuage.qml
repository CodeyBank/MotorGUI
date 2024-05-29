import QtQuick 2.15

Item {
    property string fontfamily: "This is a string"
    property real measuredvalue: 1.4
    property string unit: "mA"
    property string variablename: "Ia"
    property alias intFP : fp
    Rectangle {
        id: rectangle
        anchors.fill: parent

        // color: "#363651"
        gradient: Gradient{
            GradientStop {position: 0.0; color: "#025346"}
            GradientStop {position: 0.8; color: "#011512"}
        }
        radius: rectangle.width
        border.color: "#f7f0f0"
        border.width: 10

        Text {
            id: text1
            y: 42
            width: 70
            height: 40
            color: "#ffffff"
            text: measuredvalue
            anchors.bottom: parent.bottom
            font.letterSpacing: -1.9
            font.pixelSize: 40
            horizontalAlignment: Text.AlignHCenter
            lineHeight: 1.6
            topPadding: 0
            style: Text.Raised
            anchors.bottomMargin: 57
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Courier"

        }

        Rectangle {
            id: rectangle1
            width: rectangle.width * 0.70
            height: 1
            color: "#ffffff"
            border.color: "#ffffff"
            border.width: 1
            anchors.top: text1.bottom
            anchors.topMargin: 7
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: text2
            color: "#fdfafa"
            text: variablename
            anchors.top: rectangle1.bottom
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Courier"
        }

        Text {
            id: text3
            width: 50
            height: 50
            color: "#fcfbfb"
            text: unit
            anchors.top: parent.top
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            font.family: "Courier"
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
    MouseArea{
        anchors.fill: parent
        onDoubleClicked: {
            // internal.loadItems(fp.intTaglist, udpworker.variablelist)
            fp.visible =  true
            internal.loadItems(intFP.intTaglist, udpworker.variablelist)
        }
    }

    FacePlate{
        id: fp
        intBind.onClicked: {
            unit = intUnit.text
            variablename = intAlias.text
            bindingmodel.addBinding(intHeading.text, intTaglist.currentText, "read" )
        }
    }

}
