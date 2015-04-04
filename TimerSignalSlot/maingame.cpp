#include "maingame.h"

MainGame::MainGame(QObject *parent) : QObject(parent)
{

    roundNumber = 0;
    maxRounds = 0;

    mainTimer = new QTimer(this);   // Create a new timer and make it a child of MainGame
    mainTimer->setInterval(1000);   // set interval in ms

    //Signal Slot connection. Must be SIGNAL SLOT or Signal Signal.
    //Number, order and type of arguments must match.
    connect(mainTimer,SIGNAL(timeout()),this,SLOT(RoundElapsed()));

}

void MainGame::StartGame(){
    qDebug() << " Game started. ";
    mainTimer->start();
    roundNumber = 0;
}


void MainGame::RoundElapsed(){
    qDebug() << " Round " << roundNumber << " has elapsed.";
    if(roundNumber < maxRounds){
        roundNumber++;
    }else{
        emit GameEnded();
    }
}



MainGame::~MainGame()
{

}

