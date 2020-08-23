#include "element.h"
#include <QPainter>
#include<QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QtDebug>

Element::Element(bool P){
    Pressed=P;
    setFlag(ItemIsMovable);
}


QRectF Element::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void Element::paint(QPainter *painter, const QStyleOptionGraphicsItem *opcion, QWidget *widget)
{
    QRectF rec= boundingRect();
    QBrush brush(Qt::black);
    if(Pressed){
      brush.setColor(Qt::gray);

    }
    else{
      brush.setColor(Qt::black);
    }
    painter->fillRect(rec,brush);
    painter->drawRect(rec);


}

void Element::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   //Pressed=true;
   update();
   QGraphicsItem::mousePressEvent(event);
}
