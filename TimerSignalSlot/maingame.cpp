#include "maingame.h"

MainGame::MainGame(QObject *parent) : QObject(parent)
{

    roundNumber = 0;
    maxRounds = 10;
    lives = 0;

    mainTimer = new QTimer(this);   // Create a new timer and make it a child of MainGame
    mainTimer->setInterval(1000);   // set interval in ms

    //Signal Slot connection. Must be SIGNAL SLOT or Signal Signal.
    //Number, order and type of arguments must match.
    connect(mainTimer,SIGNAL(timeout()),this,SLOT(roundElapsed()));

    connect(this,SIGNAL(GameEnded()),this,SLOT(stopGame()));

    engine = new QQmlApplicationEngine(this);
    engine->rootContext()->setContextProperty("mainGame",this);
    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));

}

void MainGame::startGame(){
    qDebug() << " Game started. ";
    mainTimer->start();
    roundNumber = 0;
    lives = 3;
    emit livesChanged();


}

void MainGame::stopGame(){
    qDebug() << " Game stopped. ";
    mainTimer->stop();
    roundNumber = 0;
    emit GameEnded();
}

quint8 MainGame::getLives(){
    return lives;
}

void MainGame::liveUp(){
    if( lives < 255){
        lives ++;
        emit livesChanged();
     }
}

void MainGame::liveDown(){
    if( lives > 1){
        lives --;
        emit livesChanged();
     }else{
        emit GameEnded();
    }
}

void MainGame::leftPressed(){
    qDebug() << "Left key Pressed";
}

void MainGame::rightPressed(){
    qDebug() << "Right key Pressed";
}

void MainGame::roundElapsed(){
    qDebug() << " Round " << roundNumber << " has elapsed.";
    if(roundNumber < maxRounds){
        roundNumber++;
    }
}



MainGame::~MainGame()
{

}

