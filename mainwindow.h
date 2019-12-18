#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void bg();

private:
    Ui::MainWindow *ui;

    quint8 r;
    quint8 g;
    quint8 b;
    QPalette pal;
    QTimer *m_colourTimer;
};

#endif // MAINWINDOW_H
