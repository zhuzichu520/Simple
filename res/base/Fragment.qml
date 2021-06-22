import QtQuick 2.9
import QtQuick.Controls 2.5
import "../view"

Page {

    property var activity
    property var controller
    property var isFirstVisible: true
    signal createView
    signal destroyView
    signal start
    signal stop
    signal lazy

    id: fragment
    visible: false

    Component.onCompleted: {
        if (controller === undefined)
            return
        createView()
        controller.onCreateView(fragment)
        initUI()
    }

    function initUI(){
        controller.onToastEvent.connect(function(text){
            toast(text)
        })
        controller.onBackEvent.connect(function(){
            back()
        })
        controller.onStartFragmentEvent.connect(function(url){
            startFragment(url)
        })
        controller.onStartActivityEvent.connect(function(url){
            startActivity(url)
        })
    }

    onVisibleChanged: {
        if(controller === undefined)
            return
        if(root.visible === true){
            start()
            controller.onStart()
            if(isFirstVisible){
                lazy()
                controller.onLazy()
                isFirstVisible = false
            }
        }
        if(root.visible === false){
            stop()
            controller.onStop()
        }
    }

    Component.onDestruction: {
        onDestroyView()
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

}
