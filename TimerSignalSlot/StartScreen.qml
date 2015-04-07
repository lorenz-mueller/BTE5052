import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import "BasicLogic.js" as BasicLogic

Rectangle{
    anchors.fill: parent;
    readonly property real dip: Screen.pixelDensity / (96 / 25.4) // DPI norm in mm
    id:main;

    // The background image
       Image {
           source:  "pictures/startBackground.jpg"
           anchors.fill: parent;
           fillMode: Image.Tile
       }

    Button{
        anchors.centerIn: parent
        text: qsTr("Start Game");
        onClicked: {
            mainGame.startGame();
            BasicLogic.showGameScreen();
        }
        width: 100 * dip;
        height: 50 * dip;
    }



}

