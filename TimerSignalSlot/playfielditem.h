#ifndef PLAYFIELDITEM_H
#define PLAYFIELDITEM_H

#include <QObject>
#include <QDebug>

class PlayfieldItem : public QObject
{
    Q_OBJECT
public:
    explicit PlayfieldItem(QObject *parent = 0, QString icon="");
    ~PlayfieldItem();

    double getX();
    double getY();

    QString getIcon();

    Q_PROPERTY(double xOrdinate READ getX NOTIFY xChanged)
    Q_PROPERTY(double yOrdinate READ getY NOTIFY yChanged)
    Q_PROPERTY(QString icon READ getIcon NOTIFY iconChanged)

signals:
    void xChanged();
    void yChanged();
    void iconChanged();


public slots:
   void timerSlot();

private:
    double x;
    double y;
    double speed;
    QString icon;

};

#endif // PLAYFIELDITEM_H

