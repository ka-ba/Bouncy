#include "bouncywindow.h"
#include "ui_bouncywindow.h"

BouncyWindow::BouncyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BouncyWindow)
{
    ui->setupUi(this);
}

BouncyWindow::~BouncyWindow()
{
    delete ui;
}
