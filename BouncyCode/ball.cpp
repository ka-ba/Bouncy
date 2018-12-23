#include "ball.h"
#include <QPainter>
#include <random>
#include <QDebug>

using namespace std;

template<typename T> T randoR( T l, T h );
template<typename T> T randoI( T l, T h );
//double rando( double l, double h );
//float rando( float l, float h );
//int rando( int l, int h );

Ball::Ball() :
    QGraphicsItem(),
    pos(QPoint(randoR<double>(-100.0,100.0),randoR<double>(-100.0,100.0))),
    speed(QVector2D(randoR<float>(-3.0,3.0),randoR<float>(-3.0,3.0))),
    size(randoR<float>(2.0,4.0)),
    colour(QColor(randoI<int>(0,255),randoI<int>(0,255),randoI<int>(0,255)))
{
    bounds = QRectF( -1*ceil(size), -1*ceil(size), ceil(size)*2, ceil(size)*2 );
    qDebug() << "created ball at" << pos.x() << "," << pos.y() << "size" << size;
}

QRectF Ball::boundingRect() const
{
    return bounds;
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush( colour );
    painter->drawEllipse( pos, size, size );
}

void Ball::advance(int phase)
{
    return;  // FIXME: TODO: nothing for now...
}

QPoint Ball::getPos() const {
    return pos;
}

default_random_engine _Ball_RandomEngine_;

template<typename T>
T randoR(T l, T h ){
    uniform_real_distribution<T> unif(l,h);
//    default_random_engine re;
    return unif(_Ball_RandomEngine_);
}

template<typename T>
T randoI(T l, T h ){
    uniform_int_distribution<T> unif(l,h);
//    default_random_engine re;
    return unif(_Ball_RandomEngine_);
}
