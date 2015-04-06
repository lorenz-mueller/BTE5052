#include "maingame.h"

MainGame::MainGame(QObject *parent) : QObject(parent)
{

    roundNumber = 0;
    maxRounds = 10;

    mainTimer = new QTimer(this);   // Create a new timer and make it a child of MainGame
    mainTimer->setInterval(1000);   // set interval in ms

    //Signal Slot connection. Must be SIGNAL SLOT or Signal Signal.
    //Number, order and type of arguments must match.
    connect(mainTimer,SIGNAL(timeout()),this,SLOT(roundElapsed()));

    connect(this,SIGNAL(GameEnded()),this,SLOT(stopGame()));

    engine = new QQmlApplicationEngine(this);
    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
    engine->rootContext()->setContextProperty("mainGame",this);

}

void MainGame::startGame(){
    qDebug() << " Game started. ";
    mainTimer->start();
    roundNumber = 0;
}

void MainGame::stopGame(){
    qDebug() << " Game stopped. ";
    mainTimer->stop();
    roundNumber = 0;
}


void MainGame::roundElapsed(){
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

