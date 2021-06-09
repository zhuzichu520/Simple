import QtQuick 2.9
import "../base"

Activity {

    id:application
    Component.onCompleted: {
        close()
        startActivity("qrc:/layout/ActivityMain.qml")
    }

    function startActivity(url){
        var object= Qt.createComponent(url).createObject(application)
        object.show()
    }

}
