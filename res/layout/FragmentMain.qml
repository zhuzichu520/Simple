import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import "../base"
import "../global"

Fragment {

    id:root

    property int current: 0

    width: parent.width

    ListModel{
        id:tabModel
        ListElement{
            name:"首页"
            icon:"qrc:/drawable/ic_main_home.png"
            index:0
        }
        ListElement{
            name:"工具"
            icon:"qrc:/drawable/ic_main_tool.png"
            index:1
        }
    }

    Rectangle{
        id:tab
        color: "#FF455B55"
        width: 70
        anchors{
            left: parent.lelt
            top:parent.top
            bottom:parent.bottom
        }
        ListView{
            anchors.fill: parent
            model:tabModel
            delegate: tabDelegate
        }
    }

    StackLayout{
        id:content
        anchors{
            top: tab.top
            bottom: tab.bottom
            left: tab.right
            right: parent.right
        }
        currentIndex:current
        FragmentHome{

        }
        FragmentTool{

        }
    }

    Component{
        id:tabDelegate
        Item{
            width: parent.width
            height: 64
            Column{
                anchors.centerIn: parent
                Image {
                    id:tabIcon
                    height: 22
                    width: 22
                    source: icon
                    opacity: (current === index)?1:0.3
                }
                Text {
                    text: qsTr(name)
                    width: parent.width
                    color: Color.color_FFFFFFFF
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 12
                    topPadding: 5
                    opacity: (current === index)?1:0.3
                }
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    current = index
                }
            }
        }
    }
}
