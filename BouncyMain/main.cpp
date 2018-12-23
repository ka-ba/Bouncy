#include "bouncywindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>
#include "ball.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "off we go...";
    QGraphicsScene scene;
    scene.setSceneRect( -105, -105, 210, 210 );
    scene.setItemIndexMethod( QGraphicsScene::BspTreeIndex );
    for( int i=0; i<4; i++ ) {
        qDebug() << "creating ball...";
        Ball *b = new Ball();
        scene.addItem( b );
    }
    QGraphicsView view(&scene);
    view.setRenderHint( QPainter::Antialiasing );
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::ScrollHandDrag);

    view.resize( 210, 210 );
    view.show();

    QTimer timer;
    QObject::connect( &timer, SIGNAL(timeout()), &scene, SLOT(advance()) );
    timer.start( 1000 / 30 );

//    BouncyWindow w;
//    w.show();

    return a.exec();
}
