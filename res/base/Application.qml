import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.5

ApplicationWindow{

    id:application
    flags: Qt.Window | Qt.FramelessWindowHint | Qt.CustomizeWindowHint

    Component.onCompleted: {
        var x = (Screen.desktopAvailableWidth - application.width) / 2
        var y = (Screen.desktopAvailableHeight - application.height) / 2
        application.setGeometry(x, y, application.width, application.height)
        close()
        startActivity("qrc:/layout/ActivityMain.qml")
    }

    function startActivity(url){
        var object= Qt.createComponent(url).createObject(application)
        object.show()
    }

}
