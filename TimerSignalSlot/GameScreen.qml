import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

import "BasicLogic.js" as BasicLogic

Item{
    anchors.fill: parent;
    focus: true
   readonly property real dip: Screen.pixelDensity / (96 / 25.4) // DPI norm in mm

     Rectangle{
            border.color: "blue";
            width: parent.width
            height: 100*dip;

            Text {
                id: name
                text: qsTr("Lives: ") + mainGame.lives;
            }
    }

    Keys.onRightPressed: {
        console.log("Right pressed");
        mainGame.leftPressed();

    }
    Keys.onLeftPressed: {
        console.log("Left pressed");
        mainGame.rightPressed();
    }

}

