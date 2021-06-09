import QtQuick 2.9
import QtQuick.Window 2.3

Row {

    property var helper
    property bool active: Window.active
    property bool noWarning: false
    property string color: "black"
    signal closeEvent

    id: control
    anchors {
        top: parent.top
        right: parent.right
        margins: 1
    }

    ButtonMinimize {
        color: control.color
        onClicked: {helper.triggerMinimizeButtonAction()}
    }

    ButtonMaximize {
        color: control.color
        onClicked: {helper.triggerMaximizeButtonAction()}
    }

    ButtonClose {
        color: control.color
        onClicked: closeEvent()
    }
}
