import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4
import QtQuick.Extras.Private 1.0

Item {
    property alias intGauge:speedgauge
    property alias measuredvalue : speedgauge.value

    CircularGauge {
        id: speedgauge
        anchors.fill: parent
        value: accelerating ? maximumValue : 0
        anchors.centerIn: parent
        // foreground: Item{}

        style: CircularGaugeStyle{
            tickmarkLabel:  Text {
                font.pixelSize: Math.max(6, outerRadius * 0.1)
                text: styleData.value
                color: styleData.value >= 80 ? "#e34c22" : "white"
                antialiasing: true
            }
            minorTickmark: Rectangle {
                             visible: styleData.value < 80
                             implicitWidth: outerRadius * 0.01
                             antialiasing: true
                             implicitHeight: outerRadius * 0.03
                             color: "white"
            }
            tickmark: Rectangle {
                             visible: styleData.value < 80 || styleData.value % 10 == 0
                             implicitWidth: outerRadius * 0.02
                             antialiasing: true
                             implicitHeight: outerRadius * 0.06
                             color: styleData.value >= 80 ? "#e34c22" : "white"
            }

            function degreesToRadians(degrees) {
                return degrees * (Math.PI / 180);
            }

            background: Canvas {

                onPaint: {
                    var ctx = getContext("2d");
                    ctx.reset();

                    ctx.beginPath();
                    ctx.strokeStyle = "#e34c22";
                    ctx.lineWidth = outerRadius * 0.02;

                    ctx.arc(outerRadius, outerRadius, outerRadius - ctx.lineWidth / 2,
                        degreesToRadians(valueToAngle(80) - 90), degreesToRadians(valueToAngle(100) - 90));
                    ctx.stroke();

                }
            }
        }
        property bool accelerating: false

        Keys.onRightPressed:  accelerating = true
        Keys.onReleased: {
            if (event.key === Qt.Key_Right) {
                accelerating = false;
                event.accepted = true;
            }
        }

        Component.onCompleted: forceActiveFocus()

        Behavior on value {
            NumberAnimation {
                duration: 1000
            }
        }
    }
}

