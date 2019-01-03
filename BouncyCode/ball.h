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
    friend void bla( double xmi, double xma, double ymi, double yma);
    static bool setGlobalBounds( double xmi, double xma, double ymi, double yma);

protected:
    void advance(int phase) override;

private:
    QVector2D speed; // ignored for now
    float size;
    QColor colour;
    QRectF bounds;
// why not ???????? error: 'constexpr' needed for in-class initialization of static data member 'double Ball::xmin' of non-integral type [-fpermissive]
//    static double xmin=-100.0, xmax=100.0, ymin=-100.0, ymax=100.0;
//    static double cre_xi=-90.0, cre_xa=90.0, cre_yi=-90.0, cre_ya=90.0;
//    static bool global_bounds_set=false;
    // init done in cpp ...
    static double xmin, xmax, ymin, ymax;
    static double cre_xi, cre_xa, cre_yi, cre_ya;
    static bool global_bounds_set;

//signals:

//public slots:

};

#endif // BALL_H
