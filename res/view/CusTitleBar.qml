import QtQuick 2.9

Item {

    property alias color: bg.color

    id: titleBar

    Rectangle{
        id:bg
        anchors.fill: parent
    }

}
