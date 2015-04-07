#include "playfielditem.h"

PlayfieldItem::PlayfieldItem(QObject *parent, QString icon) : QObject(parent)
{
    x = (double) qrand() / (double) RAND_MAX;
    y = 0;
    speed=0.001;
    this->icon = icon;


}

void PlayfieldItem::timerSlot(){
    y=y+speed;
    emit yChanged();
    //qDebug() << " Playfield item at: " << getX();
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

}

