import QtQuick 2.0
// import QtQuick.Controls 2.15
import QtCharts 2.15

Item {
    Rectangle{
        anchors.fill: parent
        color: "#dedede"
        anchors.margins: 10
        radius: 50

        // ChartView {
        //         id: chartView
        //         anchors.fill: parent
        //         legend.visible: false

        //         LineSeries {
        //             id: lineSeries
        //             name: "Data"
        //             XYPoint { x: 0; y: 0 } // Initial data point
        //         }
        //     }

        //     Connections {
        //         target: udpworker // Connect to C++ backend
        //         // onUpdateVariableData: {
        //         //     lineSeries.append(variable, value); // Append new data point to the series
        //         //     chartView.scroll(horizontalOffset + 10, 0); // Optionally scroll the chart horizontally
        //         // }
        //     }
    }
}
