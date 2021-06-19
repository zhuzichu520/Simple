import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.5
import "../base"

Activity {
    width: 878
    height: 595
    minimumWidth: 878
    minimumHeight: 595
    visible: true
    Component.onCompleted: {
        startFragment("qrc:/layout/FragmentMain.qml")
    }
}
