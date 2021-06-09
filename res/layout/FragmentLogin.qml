import QtQuick 2.9
import QtQuick.Controls 2.5
import "../base"

Fragment {


    title:"登录页面"

    Button{
        anchors.centerIn: parent
        text: "返回主界面"
        onClicked: {
            back()
        }
    }


}
