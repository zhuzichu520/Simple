import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.5
import "../base"

Activity {
    id: activity
    width: 400
    height: 400
    minimumHeight: 200
    minimumWidth: 300
    Component.onCompleted: {
        startFragment("qrc:/layout/FragmentLogin.qml")
    }
}
