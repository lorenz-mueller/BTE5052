import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import "BasicLogic.js" as BasicLogic

Rectangle{
    width: parent.width/2;
    height: parent.height/2;
    anchors.centerIn: parent;
    readonly property real dip: Screen.pixelDensity / (96 / 25.4) // DPI norm in mm

    border.color: "#2C1F55"
    border.width: 10*dip
    radius: 10*dip

     color: "black"
     opacity: .5
    Text{
        anchors.centerIn: parent;
        text: qsTr("Score: 3000");
        color: "white"
        font.pixelSize: 40*dip;
    }


    MouseArea{
        anchors.fill: parent
        onClicked: BasicLogic.showStartScreen()
    }


}

