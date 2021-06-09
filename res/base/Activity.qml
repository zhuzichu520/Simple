import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.3
import QtGraphicalEffects 1.0
import QtQuick.Window 2.3
import QtShark.Window 1.0
import "../view"

ApplicationWindow {

    property int titleBarHeight:28

    id:root
    flags: Qt.Window | Qt.FramelessWindowHint | Qt.CustomizeWindowHint

    onClosing: function(closeevent){
        closeevent.accepted = false
        root.destroy()
    }

    FramelessHelper {
        id: frameless
        titleBarHeight: root.titleBarHeight
        Component.onCompleted: {
            addIncludeItem(titleBar)
            addExcludeItem(controls)
        }
    }

    StackView {
        id:container
        width: parent.width
        anchors{
            top: titleBar.bottom
            bottom: parent.bottom
        }
    }

    CusTitleBar {
        id: titleBar
        height: titleBarHeight
        width: parent.width
        color: "#EFEFEF"
    }

    WindowBorder {
        foregroundColor: "#FF4F7DA4"
    }

    ThreeButtons {
        id: controls
        helper: frameless
        onCloseEvent: {
            root.destroy()
        }
    }

    function startFragment(url){
        container.push(Qt.resolvedUrl(url),{activity:root})
    }

    function startActivity(url){
        application.startActivity(url)
    }

    function back(){
        if(container.depth>1){
            container.pop()
        }else{
            root.destroy()
        }
    }
}
