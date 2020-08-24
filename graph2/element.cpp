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

    return QRectF(0,0,141,141);
}

void Element::paint(QPainter *painter, const QStyleOptionGraphicsItem *opcion, QWidget *widget)
{
    QRectF rec= boundingRect();
    QBrush brush(QPixmap(":/Recursos/resistror141.jpg"));
    if(Pressed){
      brush.setTexture(QPixmap(":/Recursos/resistror141.jpg"));

    }
    else{
      brush.setTexture(QPixmap(":/Recursos/source141.jpg"));
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
