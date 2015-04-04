#ifndef MAINGAME_H
#define MAINGAME_H

#include <QObject>                                  //Include QObject so the type is known
#include <QTimer>
#include <QDebug>

class MainGame : public QObject                     //Inherit from QObject
{
    Q_OBJECT                                        //Insert Q_OBJECT Macro, needed by MOC to work
public:
    explicit MainGame(QObject *parent = 0);
    ~MainGame();

signals:
    void GameEnded();

public slots:
    void RoundElapsed();
    void StartGame();


private:
    QTimer* mainTimer;
    quint8 roundNumber;
    quint8 maxRounds;

};

#endif // MAINGAME_H
