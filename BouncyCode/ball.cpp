#include "ball.h"
#include <QPainter>
#include <random>
#include <QDebug>

using namespace std;

template<typename T> T randoR( T l, T h );
template<typename T> T randoI( T l, T h );
template<typename T> void sortPair( T& a, T& b );

// defining static class members (can't be done in h when lib :/ )
double Ball::xmin=-100.0, Ball::xmax=100.0, Ball::ymin=-100.0, Ball::ymax=100.0;
double Ball::cre_xi=-90.0, Ball::cre_xa=90.0, Ball::cre_yi=-90.0, Ball::cre_ya=90.0;
bool Ball::global_bounds_set=false;

Ball::Ball() :
    QGraphicsItem(),
    speed(QVector2D(randoR<float>(-5.0,5.0),randoR<float>(-5.0,5.0))),
    size(randoR<float>(2.0,4.0)),
    colour(QColor(randoI<int>(0,255),randoI<int>(0,255),randoI<int>(0,255)))
{
    setPos( QPointF(randoR<double>(xmin,xmax), randoR<double>(ymin,ymax)) );
    bounds = QRectF( -1*ceil(size), -1*ceil(size), ceil(size)*2, ceil(size)*2 );
    qDebug() << "created ball at" << pos().x() << "," << pos().y() << "size" << size;
    global_bounds_set = true; // implicitely set to defaults...
}

QRectF Ball::boundingRect() const
{
    return bounds;
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush( colour );
    painter->drawEllipse( pos(), size, size );
}

void Ball::advance(int phase)
{
    if( phase == 0 )
        return;
//    qDebug() << "advance..." << phase;
    double new_x = pos().x() + speed.x();
    double new_y = pos().y() + speed.y();
    if( new_x < xmin ) {
        new_x = xmin + ( xmin - new_x );
        speed.setX( - speed.x() );
    }
    if( new_x > xmax ) {
        new_x = xmax - ( xmax - new_x );
        speed.setX( - speed.x() );
    }
    if( new_y < ymin ) {
        new_y = ymin + ( ymin - new_y );
        speed.setY( - speed.y() );
    }
    if( new_y > ymax ) {
        new_y = ymax - ( ymax - new_y );
        speed.setY( - speed.y() );
    }
//    qDebug() << "moving from " << pos().x() << "," << pos().y() << "to" << new_x << "," << new_y;
    setPos( new_x, new_y );
    return;
}

void bla( double xmi, double xma, double ymi, double yma) {
        sortPair<double>( xmi, xma );
        sortPair<double>( ymi, yma );
        Ball::xmin=xmi; Ball::xmax=xma; Ball::ymin=ymi; Ball::ymax=yma;
        Ball::cre_xi = xmi + ((xma-xmi)*.05);
        Ball::cre_xa = xma - ((xma-xmi)*.05);
        Ball::cre_yi = ymi + ((yma-ymi)*.05);
        Ball::cre_ya = yma - ((yma-ymi)*.05);
}

/*static*/ bool Ball::setGlobalBounds( double xmi, double xma, double ymi, double yma) {
    if( global_bounds_set )
        return false;
    sortPair<double>( xmi, xma );
    sortPair<double>( ymi, yma );
    xmin=xmi; xmax=xma; ymin=ymi; ymax=yma;
    cre_xi = xmi + ((xma-xmi)*.05);
    cre_xa = xma - ((xma-xmi)*.05);
    cre_yi = ymi + ((yma-ymi)*.05);
    cre_ya = yma - ((yma-ymi)*.05);
//    _Ball_RandomEngine_.seed();
    return global_bounds_set = true;
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

template<typename T>
void sortPair( T& a, T& b ) {
    if( b < a ) {
        T x = a;
        a = b;
        b = x;
    }
}
