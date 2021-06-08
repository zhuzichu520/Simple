import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.5

Window {
    id:root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle{
        id:bg
        anchors.fill: parent

    }
    Button{
        text: "按钮"
        anchors{
            verticalCenter: parent.verticalCenter
            horizontalCenter: parent.horizontalCenter
        }
        onClicked: {
           root.close()
        }
    }
}