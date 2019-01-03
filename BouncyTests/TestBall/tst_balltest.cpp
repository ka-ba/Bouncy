#include <QString>
#include <QtTest>
#include "ball.h"

class BallTest : public QObject
{
    Q_OBJECT

public:
    BallTest();

private Q_SLOTS:
    void testRandInit();
};

BallTest::BallTest()
{
}

void BallTest::testRandInit()
{
    srand((unsigned)time(0));
    for( int i=0; i<10; i++ ) {
        Ball b;
        QPointF p = b.pos();
        QVERIFY2( -100.0 <= p.x(), "illegal x-pos (too small)" );
        QVERIFY2( p.x() <= 100.0, "illegal x-pos (too large)" );
        QVERIFY2( -100.0 <= p.y(), "illegal y-pos (too small)" );
        QVERIFY2( p.y() <= 100.0, "illegal y-pos (too large)" );
    }
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(BallTest)

#include "tst_balltest.moc"
