import QtQuick 2.9

Item {

    property alias color: bg.color

    id: titleBar
    height: 28
    width: parent.width

    Rectangle{
        id:bg
        anchors.fill: parent
    }

}
