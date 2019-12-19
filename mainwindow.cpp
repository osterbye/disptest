#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    r = 0;
    g = 0;
    b = 0;
    pal.setColor(QPalette::Background, QColor(r, g, b));
    ui->centralWidget->setAutoFillBackground(true);
    ui->centralWidget->setPalette(pal);

    m_colourTimer = new QTimer();
    connect(m_colourTimer, SIGNAL(timeout()), this, SLOT(bg()));
    m_colourTimer->setSingleShot(true);
    m_colourTimer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::bg()
{
    if (r < 255) {
        ++r;
    } else if (g < 255) {
        ++g;
    } else if (b < 255) {
        ++b;
    } else {
        r = 0;
        g = 0;
        b = 0;
    }
    pal.setColor(QPalette::Background, QColor(r, g, b));
    ui->centralWidget->setPalette(pal);
    repaint();
    m_colourTimer->start(10);
}
