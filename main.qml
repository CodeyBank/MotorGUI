import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.15
import QtQuick.Dialogs 1.0
import QtQuick.Layouts 1.15

import com.futureelctronics.appmanager 1.0
import com.futureelctronics.udpworker 1.0
import com.futureelctronics.memorymodel 1.0
import com.futureelctronics.modelmanager 1.0



ApplicationWindow {
    id: mainwindow
    title: qsTr("BLDC Motor Control Simulator")
    width: 1620
    // height: 985
    minimumWidth: 1208
    minimumHeight: 900
    color: "#00000000"
    visible: true
    property string varguage1: "dummy"
    property string varguage2: "dummy"
    property string varguage3: "dummy"
    property string varguage4: "dummy"
    property string varguage5: "dummy"
    property string varguage6: "dummy"
    property string varguage7: "dummy"
    property string sguage: "dummy"
    property string fault: "dummy"

    // Window properties. 0 means the window isnt maximized
    property int windowStatus: 0
    // // window margins
    property int windowMargin: 1

    // Remove the title  bar
    flags: Qt.Window | Qt.FramelessWindowHint

    // Internal Fucntions
    QtObject {
        id: internal
        function resetResizeWindows() {
            // Hide resize effects
            resizeBottom.visible = true
            resizeLeft.visible = true
            resizeRight.visible = true
            diagResize.visible = true
        }

        function maximizeRestore() {
            if (windowStatus == 0) {
                mainwindow.showMaximized()
                windowStatus = 1
                windowMargin = 0
                maintopbar.intmaxrestore.btnIconSource = "qrc:/images/images/svg_images/restore_icon.svg"
                // Hide resize effects
                resizeBottom.visible = false
                resizeLeft.visible = false
                resizeRight.visible = false
                diagResize.visible = false
            } else {
                mainwindow.showNormal()
                windowStatus = 0
                windowMargin = 1
                internal.resetResizeWindows()
                maintopbar.intmaxrestore.btnIconSource
                        = "qrc:/images/images/svg_images/maximize_icon.svg"
            }
        }

        function ifMaximisedWindowRestore() {
            if (windowStatus == 0) {
                mainwindow.showNormal()
                windowStatus = 0
                windowMargin = 1
                internal.resetResizeWindows()
                maintopbar.intmaxrestore.btnIconSource
                        = "qrc:/images/images/svg_images/maximize_icon.svg"
            }
        }
        function restoreMargins() {
            windowMargin = 10
            windowStatus = 0
            internal.resetResizeWindows()
            maintopbar.intmaxrestore.btnIconSource = "qrc:/images/images/svg_images/maximize_icon.svg"
        }

        function loadItems(obj, list){


            var jsArray = [];

            for (var i = 0; i < list.length; ++i) {
                var element = list[i];
                jsArray.push(element);
            }
            obj.model = jsArray
        }


        function getChildrenNames(item) {
                var result = [] // Initialize an empty list to store object names

            if(item.objectName !=="" ){
                result.push(item.objectName) // Add the current item's objectName to the result

            }
                // Recurse into child items
                for (var i = 0; i < item.children.length; ++i) {
                    result = result.concat(getChildrenNames(item.children[i]))
                }

                return result
            }

        function findChild(rootItem, name){

            if (!rootItem || !name) return null;
            if (rootItem.objectName === name)
                return rootItem;

            // Recursively search visual children
            for (var i = 0; i < rootItem.children.length; ++i) {
                var child = rootItem.children[i];
                var foundObject = findChild(child, name);
                if (foundObject)
                    return foundObject;
            }

            return null; // Not found
        }

        function bindObject(variable, object){
            variable = object
            console.log("called binding function")
        }

        function formatValue(value) {
                // Convert the QVariant to a JavaScript number
                var floatValue = parseFloat(value);

                // Check if the value is a valid number
                if (!isNaN(floatValue)) {
                    // Round the value to two decimal places
                    return floatValue.toFixed(2);
                } else {
                    // Handle non-numeric or invalid values
                    return "Invalid";
                }
            }

    }


    UDPWorker{
        id: udpworker
        onNewDataReceived: {
            memorymodel.updateData(data.name, data.address, data.attribute, data.type, data.size, 0);
        }

        onModifiedDataReceived: {
            memorymodel.modifyData(data.name, data.address, data.attribute,data.type, data.size, data.value);
        }
        onVariableListChanged: {
            internal.loadItems(tagbindings.varlist, udpworker.variablelist)
        }

        onVmapChanged: {
            // var v = udpworker.vmap
        }

        onNewVariableRecieved: {
            // console.log("Received new variable " + variable)
           // obj = variableManager.get(variable)
           // console.log("Model manager returned " + obj)
        }

        onUpdateVariableData: {
            console.log("Received new value for "+ variable +"value "+ value)
            variableManager.update(variable, value)
            // console.log(" *****Parsed value: "+ internal.formatValue(variableManager.get(varguage1)))
            dashboard.g1.measuredvalue = internal.formatValue(variableManager.get(varguage1))
            dashboard.g2.measuredvalue = internal.formatValue(variableManager.get(varguage2))
            dashboard.g3.measuredvalue = internal.formatValue(variableManager.get(varguage3))
            dashboard.g5.measuredvalue = internal.formatValue(variableManager.get(varguage5))
            dashboard.g6.measuredvalue = internal.formatValue(variableManager.get(varguage6))
            dashboard.g7.measuredvalue =internal.formatValue(variableManager.get(varguage7))
            dashboard.g4.measuredvalue = internal.formatValue(variableManager.get(varguage4))/10
        }
    }

    ModelManager{
        id: variableManager
    }


    MemoryModel{
        id: memorymodel
    }

    AppManger{
        id: appmanager
        onRemoteHeartBeatChanged:  {
            // console.log(appmanager.heartbeat)
            dashboard.control.connected = appmanager.heartbeat
            dashboard.enabled = appmanager.heartbeat
            networkPage.connect.enabled =appmanager.heartbeat
            networkPage.disconnect.enabled = appmanager.heartbeat
        }

        onLocalinterfacesChanged: {
            // console.log("Interface changed emitted")
            internal.loadItems(networkPage.intLocalComboBox, appmanager.localinterfaces)
        }

    }


    DragHandler {
        target: maintopbar
        onActiveChanged: if (active) {
                             mainwindow.startSystemMove()
                             internal.ifMaximisedWindowRestore()
                         }
    }

    Rectangle {
        id: appContainer
        color: "#00000000"
        anchors.fill: parent
        border.color: "#383e4c"

        Rectangle {

            id: bg
            color: "white"
            border.color: "#343644"
            anchors.right: parent.right
            // anchors.rightMargin: windowMargin
            anchors.left: parent.left
            // anchors.leftMargin: windowMargin
            anchors.bottom: parent.bottom
            // anchors.bottomMargin: windowMargin
            anchors.top: parent.top
            // anchors.topMargin: windowMargin
            z: 1

            TopBar{
                height: 60
                id: maintopbar
                anchors.top: parent.top
                anchors.right: parent.right
                anchors.left: parent.left
                intbtn.onClicked: sidebar.animate.running = true

            }

            SideBar{
                id:sidebar
                width: intwidth
                anchors.top: maintopbar.bottom
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                z:0
                intBtnConfig.onClicked: {
                    swipeview.setCurrentIndex(3)
                    appmanager.loadInterfaces()
                }
                intBtnHome.onClicked:  swipeview.setCurrentIndex(0)
                intBtnPlot.onClicked: {
                    swipeview.setCurrentIndex(2)
                }
                intBtnTagTable.onClicked: swipeview.setCurrentIndex(1)

                intBtnSettings.onClicked: swipeview.setCurrentIndex(4)
            }

            Rectangle {
                id: contentPages
                color: "#ebebeb"
                clip: true
                border.color: "#00000000"
                anchors.right: parent.right
                anchors.rightMargin: 5
                anchors.left: sidebar.right
                anchors.leftMargin: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 25
                anchors.top: maintopbar.bottom
                anchors.topMargin: 0
                radius: 10


                // SplitView{}
                ColumnLayout{
                    id: col
                    spacing: 1
                    anchors.fill: parent

                    SwipeView{
                        id: swipeview
                        Layout.alignment: Qt.AlignCenter
                        currentIndex: 0
                        Layout.preferredWidth: contentPages.width
                        Layout.preferredHeight: contentPages.height/2
                        OverviewPage{
                            id: overviewpage
                            height: parent.height
                        }
                        TagTable{
                            id: tagtable
                        }
                        PlotPage{
                            id:plotpage
                        }
                        NetworkConnectionPage{
                            id: networkPage
                        }
                        TagBindings{
                            id: tagbindings
                            // enabled: false
                            Component.onCompleted: {
                                // Start DFS from the parentItem
                                var dfsResult = internal.getChildrenNames(dashboard)
                                // console.log("DFS result:", dfsResult)
                                objList.model = dfsResult;

                            }

                            bind.onClicked: {

                                var obj = internal.findChild(dashboard, objList.currentText)
                                if(write.checked){
                                    udpworker.addCommand(varlist.currentText, objList.currentText, "write")
                                }else if(read.checked){
                                    if(obj){
                                        obj.measuredvalue = udpworker.vmap[varlist.currentText]
                                    }else{
                                        console.log("Select a valid GUI object")
                                    }
                                }
                            }
                        }

                    }
                    PageIndicator{
                        id: pageindicator
                        currentIndex: swipeview.currentIndex
                        count: swipeview.count
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                        // z:1
                    }
                    DashBoard {
                        id: dashboard
                        Layout.preferredWidth: contentPages.width
                        Layout.preferredHeight: contentPages.height/2 - pageindicator.height
                        Layout.leftMargin: 10
                        Layout.rightMargin: 10
                        enabled: false
                    }

                }

                }
            }


     MouseArea {
            id: resizeBottom
            height: 10
            anchors.top: bg.bottom
            anchors.topMargin: 0
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            cursorShape: Qt.SizeVerCursor

            DragHandler {
                target: null
                onActiveChanged: if (active) {
                                     mainwindow.startSystemResize(Qt.BottomEdge)
                                 }
            }
        }
      MouseArea {
          id: resizeRight
          width: 10
          anchors.right: parent.right
          anchors.leftMargin: 0
          anchors.bottom: parent.bottom
          anchors.bottomMargin: 10
          anchors.top: parent.top
          anchors.topMargin: 10
          cursorShape: Qt.SizeHorCursor

          DragHandler {
              target: null
              onActiveChanged: if (active) {
                                   mainwindow.startSystemResize(Qt.RightEdge)
                               }
          }
      }

       MouseArea {
           id: resizeLeft
           width: 10
           anchors.left: parent.left
           anchors.leftMargin: 0
           anchors.bottom: parent.bottom
           anchors.bottomMargin: 10
           anchors.top: parent.top
           anchors.topMargin: 10
           cursorShape: Qt.SizeHorCursor

           DragHandler {
               target: null
               onActiveChanged: if (active) {
                                    mainwindow.startSystemResize(Qt.LeftEdge)
                                }
           }
       }

       MouseArea {
           id: diagResize
           x: 881
           y: 0
           width: 25
           height: 25
           anchors.bottom: parent.bottom
           anchors.bottomMargin: 0
           anchors.right: parent.right
           anchors.rightMargin: 0
           cursorShape: Qt.SizeFDiagCursor

           DragHandler {
               target: null
               onActiveChanged: if (active) {
                                    mainwindow.startSystemResize(
                                                Qt.RightEdge | Qt.BottomEdge)
                                    console.log(mainwindow.width + "x" + mainwindow.height)
                                }
           }
       }

    }


}
