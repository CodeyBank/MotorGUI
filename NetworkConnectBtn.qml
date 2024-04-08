import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.0

Item {
    property color connection_indicator_col: "#ff061f"
    property string connection_status_text : "Connect"

    property url btnIconSource: "qrc:/images/images/svg_images/menu_icon.svg"
    property color btnColorDefault: "#2b2c31"
    property color btnColorMouseOver: "#2a1b31"
    property color btnColorClicked: "#2b1cee"

    QtObject{
        id: propinternal

        //MOUSOVER AND MOUSECLICK COLORS
        property var dynamicColor: if(btnConnect.down){
                                        btnConnect.down ? btnColorClicked : btnColorDefault
                                  }else{
                                        btnConnect.hovered ? btnColorMouseOver : btnColorDefault
                                   }

    }


    RowLayout{
        spacing: 5
        Rectangle{
            height: 20
            width: 20
            radius: 20
            color: connection_indicator_col
            anchors.verticalCenter: parent.verticalCenter
            anchors.rightMargin: 0
        }

        Button{
            id: btnConnect
            Layout.preferredHeight: 26
            Layout.preferredWidth: 80
            icon.source:  btnIconSource
            icon.height: 24
            icon.color: "white"
            icon.width: 20
            text: connection_status_text
            background: Rectangle{
                id: bgToolBtn
                color: propinternal.dynamicColor
                radius: 20

            }

        }

    }
}
