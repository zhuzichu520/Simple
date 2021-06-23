import QtQuick 2.9
import QtQuick.Controls 2.5
import UI.Controller 1.0
import "../base"
import "../view"

Fragment {

    controller:LoginController{
    }

    onCreateView: {

    }

    onDestroyView: {

    }

    TextField {
        id:username
        font {
            pixelSize: 14
        }
        anchors{
            left:parent.left
            right:parent.right
            leftMargin: 20
            rightMargin: 20
            top:parent.top
            topMargin: 80
        }
        text:controller.username
        height: 34
        focus: true
        maximumLength: 25
        color: "#FFFF7A00"
        placeholderTextColor: "#999F9F9F"
        placeholderText: "请输入用户名"
        background: Rectangle {
            color: "#0D4F7DA4"
            radius: 3
        }
        onTextChanged: {
            controller.username = text
        }
        wrapMode: TextEdit.Wrap
    }

    TextField {
        id:password
        font {
            pixelSize: 14
        }
        anchors{
            left:username.left
            right:username.right
            top:username.bottom
            topMargin: 10
        }
        text:controller.password
        height: 34
        focus: true
        maximumLength: 15
        echoMode: TextInput.Password
        color: "#FFFF7A00"
        placeholderTextColor: "#999F9F9F"
        placeholderText: "请输入密码"
        background: Rectangle {
            color: "#0D4F7DA4"
            radius: 3
        }
        onTextChanged: {
            controller.password = text
        }
        wrapMode: TextEdit.Wrap
    }

    CusButton{
        text: "登录"
        height: 36
        width: password.width
        anchors{
            top:password.bottom
            topMargin: 20
            horizontalCenter: parent.horizontalCenter
        }
        onClicked: {
            controller.onClickLogin()
        }
    }

}
