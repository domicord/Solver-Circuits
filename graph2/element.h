#ifndef ELEMENT_H
#define ELEMENT_H
#include <QPainter>
#include<QGraphicsItem>
#include <QtDebug>

class Element:public QGraphicsItem
{
public:
    Element(bool);
    QRectF boundingRect()const;
    bool Pressed;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *opcion, QWidget *widget);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // ELEMENT_H
