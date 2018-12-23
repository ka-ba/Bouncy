#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QVector2D>

/* leaning heavily on http://doc.qt.io/qt-5/qtwidgets-graphicsview-collidingmice-example.html */

class Ball : public QGraphicsItem
{
public:
    Ball();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    // testing access only:
    QPoint getPos() const;

protected:
    void advance(int phase) override;

private:
    QPoint pos;
    QVector2D speed; // ignored for now
    float size;
    QColor colour;
    QRectF bounds;

//signals:

//public slots:

};

#endif // BALL_H
