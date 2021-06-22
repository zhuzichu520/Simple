import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.5
import Qt.labs.platform 1.1
import "../base"

Activity {

    property string appTitle: "玩Android"

    id:root
    width: 878
    height: 595
    minimumWidth: 878
    minimumHeight: 595
    visible: true
    title: qsTr(appTitle)

    Component.onCompleted: {
        startFragment("qrc:/layout/FragmentMain.qml")
    }

    SystemTrayIcon {
        id: systray
        tooltip: qsTr(appTitle)
        visible: true
        icon.source: "qrc:/favicon.ico"
        menu: Menu {
            MenuItem {
                text: qsTr("退出")
                onTriggered: {
                    Qt.quit()
                }
            }
        }

        onMessageClicked: {
            root.show()
        }

        onActivated: {
            console.log(reason)
            if(reason === SystemTrayIcon.DoubleClick) {
                root.show()
                root.raise()
                root.requestActivate()
            }
        }
    }
}
