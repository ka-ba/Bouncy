#ifndef BOUNCYWINDOW_H
#define BOUNCYWINDOW_H

#include <QMainWindow>

namespace Ui {
class BouncyWindow;
}

class BouncyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BouncyWindow(QWidget *parent = 0);
    ~BouncyWindow();

private:
    Ui::BouncyWindow *ui;
};

#endif // BOUNCYWINDOW_H
