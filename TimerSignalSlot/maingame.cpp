#include "maingame.h"

MainGame::MainGame(QObject *parent) : QObject(parent)
{

    //initiate the random number generator with a seed
     qsrand(1);

    roundNumber = 0;
    maxRounds = 10;
    lives = 0;

    roundTimer = new QTimer(this);   // Create a new timer and make it a child of MainGame
    roundTimer->setInterval(3000);   // set interval in ms

    itemTimer = new QTimer(this);
    itemTimer->setInterval(10);


    //Signal Slot connection. Must be SIGNAL SLOT or Signal Signal.
    //Number, order and type of arguments must match.
    connect(roundTimer,SIGNAL(timeout()),this,SLOT(roundElapsed()));
    connect(this,SIGNAL(GameEnded()),this,SLOT(stopGame()));
    connect(itemTimer,SIGNAL(timeout()),this,SLOT(updatePlayFieldItems()));

    //create a new QmlApplication engine and expose context properties
    engine = new QQmlApplicationEngine(this);

    //set the enemies and gifts lists as context properties, they are used as models
    updatePlayFieldItems();
    engine->rootContext()->setContextProperty("mainGame",this);
    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));

}

void MainGame::startGame(){
    qDebug() << " Game started. ";
    roundTimer->start();
    itemTimer->start();
    roundNumber = 0;
    lives = 3;
    populateEnemies();
    emit livesChanged();

}

void MainGame::stopGame(){
    qDebug() << " Game stopped. ";
    roundTimer->stop();
    itemTimer->stop();
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
    populateEnemies();
    if(roundNumber < maxRounds){
        roundNumber++;
    }
}

void MainGame::populateEnemies(){
    for(int i=0;i<3;i++){
        PlayfieldItem* enemy = new PlayfieldItem(this,"pictures/Attacker.png");
        connect(itemTimer,SIGNAL(timeout()),enemy,SLOT(timerSlot()));
        Enemies.append(enemy);
     }

}

void MainGame::updatePlayFieldItems(){
    engine->rootContext()->setContextProperty("enemies", QVariant::fromValue(Enemies));
    engine->rootContext()->setContextProperty("gifts", QVariant::fromValue(Gifts));

    qDebug() << " number of enemies: " << Enemies.size();

}


MainGame::~MainGame()
{

}

