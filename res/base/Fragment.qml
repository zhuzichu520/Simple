import QtQuick 2.9
import QtQuick.Controls 2.5

Page {

    property var activity

    id:fragment

    function startFragment(url){
        activity.startFragment(url)
    }

    function startActivity(url){
        activity.startActivity(url)
    }

    function back(){
        activity.back()
    }

}