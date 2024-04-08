import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtWebView 1.0
Item {
    Rectangle{
        anchors.fill: parent
        color: "#dedede"
        anchors.margins: 10
        radius: 50
        clip: true


        WebView {
                anchors.fill: parent
                url: "qrc:/mcat/mcat/index.html" // Replace with the path to your HTML file
            }

    }
}
