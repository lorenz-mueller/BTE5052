#include "playfielditem.h"

PlayfieldItem::PlayfieldItem(QObject *parent, QString icon) : QObject(parent)
{
    x = (double) qrand() / (double) RAND_MAX;
    y = 0;
    speed=0.001;
    this->icon = icon;
    isActive = true;

}

void PlayfieldItem::timerSlot(){
    if(isActive){
        y=y+speed;

        if(y > .9){
            isActive=false;
            emit bottomReached();
            emit itemDestroyed(this);
        }

        emit yChanged();
    }
}

double PlayfieldItem::getX(){
    return x;
}

double PlayfieldItem::getY(){
    return y;

}

QString PlayfieldItem::getIcon(){
    return icon;
}

PlayfieldItem::~PlayfieldItem()
{
    qDebug() << "Playfield item " << this << " got destroyed. ";
}

