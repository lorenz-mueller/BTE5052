import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

import "BasicLogic.js" as BasicLogic

ApplicationWindow {

    title: qsTr("Qt / QML introduction")
    width: 640
    height: 480
    //width: Screen.width;
    //height: Screen.height;

    visible: true


    GameScreen{
        id: gameScreen
        visible: false;
    }

    StartScreen{
        id: startScreen
        visible: true
    }

    EndScreen{
        id: endScreen
        visible: false
    }

    Component.onCompleted: {
        mainGame.GameEnded.connect(BasicLogic.showEndScreen);
    }

 }

