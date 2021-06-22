import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import UI.Controller 1.0
import "../base"
import "../global"

Fragment{

    id:root

    controller:ToolController{
    }

    onCreateView: {
        console.debug("FragmentTool-onCreateView")
    }

    onStart: {
        console.debug("FragmentTool-onStart")
    }

    onLazy: {
        console.debug("FragmentTool-onLazy")
    }

    onStop:{
        console.debug("FragmentTool-onStop")
    }

    onDestroyView: {
        console.debug("FragmentTool-onDestroyView")
    }

    Text {
        anchors.centerIn: parent
        text: qsTr("工具页面")
    }

}
