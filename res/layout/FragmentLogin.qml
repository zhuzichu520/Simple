import QtQuick 2.9
import QtQuick.Controls 2.5
import "../base"
import "../view"

Fragment {

    onCreateView: {
        console.debug("登录页面加载完成")
    }

    onDestroyView: {
        console.debug("登录页面销毁")
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
        height: 34
        focus: true
        maximumLength: 15
        color: "#FFFF7A00"
        placeholderTextColor: "#999F9F9F"
        placeholderText: "请输入用户名"
        background: Rectangle {
            color: "#0D4F7DA4"
            radius: 3
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
            back()
        }
    }

}
