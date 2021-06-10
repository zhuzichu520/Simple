import QtQuick 2.9
import QtQuick.Controls 2.5
import "../base"

Fragment {

    width: parent.width
    title:"主页"

    Column{
        anchors.centerIn: parent
        spacing: 20
        Button{
            text: "Fragment跳转"
            onClicked: {
                startFragment("qrc:/layout/FragmentLogin.qml")
            }
        }
        Button{
            text: "Activity跳转"
            onClicked: {
                startActivity("qrc:/layout/ActivityMessage.qml")
            }
        }
        Button{
            text: "回退触发"
            onClicked: {
                back()
            }
        }
    }
}