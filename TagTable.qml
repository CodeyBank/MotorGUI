import QtQuick 2.15
// import QtQuick.Controls 2.15
import QtQuick.Controls 1.4
import com.futureelctronics.memorymodel 1.0

Item {
    Rectangle{
        anchors.fill: parent
        color: "#dedede"
        anchors.margins: 10
        radius: 50

        TableView {

                width: parent.width
                height: parent.height
                model:memorymodel
                TableViewColumn {
                    title: "Name"
                    role: "name"
                }
                TableViewColumn {
                    title: "Adrress"
                    role: "address"
                }
                TableViewColumn {
                    title: "Attribute"
                    role: "attribute"
                }
                TableViewColumn {
                    title: "Type"
                    role: "type"
                }
                TableViewColumn {
                    title: "Size"
                    role: "size"
                }
                TableViewColumn {
                    title: "Value"
                    role: "value"
                }

               Component.onCompleted: {
                   console.log(memorymodel.columnCount())
               }
            }
    }
}
