import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.5
import "../base"

Activity {
    width: 300
    height: 400
    minimumHeight: 200
    minimumWidth: 300
    Component.onCompleted: {
        startFragment("qrc:/layout/FragmentMain.qml")
    }
}
