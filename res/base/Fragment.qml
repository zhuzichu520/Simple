import QtQuick 2.9
import QtQuick.Controls 2.5
import "../view"

Page {

    property var activity
    property var controller
    signal createView
    signal destroyView

    id: fragment

    Component.onCompleted: {
        if (controller !== undefined)
            controller.onCreateView(fragment)
        createView()
    }

    Component.onDestruction: {
        destroyView()
    }

    ToastManager {
        id: toastManager
    }

    function startFragment(url) {
        activity.startFragment(url)
    }

    function startActivity(url) {
        activity.startActivity(url)
    }

    function back() {
        activity.back()
    }

    function toast(text) {
        toastManager.show(text,1500)
    }

    function logi(text) {
        controller.logi(fragment.toString()+text)
    }

}
