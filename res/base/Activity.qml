import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.3
import QtGraphicalEffects 1.0
import QtQuick.Window 2.3
import QtShark.Window 1.0
import "../view"

ApplicationWindow {

    id:root
    flags: Qt.Dialog | Qt.FramelessWindowHint

    FramelessHelper {
        id: frameless
        titleBarHeight: 28
        Component.onCompleted: {
            addIncludeItem(titleBar)
            addExcludeItem(controls)
        }
    }

    StackView {
        id:container
        width: parent.width
        anchors{
            top:titleBar.bottom
            bottom: parent.bottom
        }
    }

    CusTitleBar {
        id: titleBar
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
