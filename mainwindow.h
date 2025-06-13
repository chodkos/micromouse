#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mazetraverser.h"

#include <QMainWindow>
#include <qtimer.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() ;
    void setMazeTraverser(MazeTraverser &_mazeTraverser);
    QMetaObject::Connection connection;
    void reset();
private slots:
    void refreshMovesCount();

    void on_pushButton_clicked();

    //zaczyna poruszanie sie robota
    void on_pushButton_toggled(bool checked);

    //ustawia strategie poruszania sie na turnLeft
    void on_pushButton_2_toggled(bool checked);

    //ustawia strategie poruszania sie na turnRight
    void on_pushButton_3_toggled(bool checked);

    void on_resetButton_clicked();

private:
    Ui::MainWindow *ui;
    MazeTraverser *mazeTraverser;
    QTimer * timer = new QTimer();
};
#endif // MAINWINDOW_H
