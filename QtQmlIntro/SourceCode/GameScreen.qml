import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

import "BasicLogic.js" as BasicLogic

Rectangle{
    id: gameScreen
    anchors.fill: parent;
    focus: true
   readonly property real dip: Screen.pixelDensity / (96 / 25.4) // DPI norm in mm


   Image {
       source:  "pictures/startBackground.jpg"
       anchors.fill: parent;
       fillMode: Image.Tile

   }

     Rectangle{
            id: statusBar
            radius: 5
            color: "#2B214A"
            width: parent.width
            height: 30*dip;

            Text {
                id: name
                text: qsTr("Lives: ") + mainGame.lives;
                font.pixelSize:  20*dip
                color: "white"

            }
    }
    Rectangle{
         id: playfield
         width: parent.width
         anchors.top: statusBar.bottom
         anchors.bottom: parent.bottom
         color: "transparent"



         Repeater { model: enemies
                Image {
                   x: xOrdinate * playfield.width;
                   y: yOrdinate* playfield.height;
                   width: 50
                   source: icon
                }
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

