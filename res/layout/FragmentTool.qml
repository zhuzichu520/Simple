import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import UI.Controller 1.0
import "../base"
import "../global"

Fragment{

    controller:ToolController{
    }

    Text {
        anchors.centerIn: parent
        text: qsTr("工具页面")
    }

    onVisibleChanged: {

    }

}
