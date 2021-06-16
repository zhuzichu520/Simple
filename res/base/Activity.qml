import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.3
import QtGraphicalEffects 1.0
import QtQuick.Window 2.3
import "../view"

ApplicationWindow {

    id:root

    onClosing: function(closeevent){
        root.destroy()
        closeevent.accepted = false
    }

    StackView {
        id:container
        width: parent.width
        anchors{
            fill:parent
        }
    }

    function startFragment(url){
        container.push(Qt.resolvedUrl(url),{activity:root})
    }

    function startActivity(url,isAttach=false){
        var object= Qt.createComponent(url).createObject(isAttach?root:null)
        object.show()
    }

    function back(){
        if(container.depth>1){
            container.pop()
        }else{
            root.destroy()
        }
    }
}
