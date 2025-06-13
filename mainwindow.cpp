#include "fileutils.h"
#include "mainwindow.h"
#include "maze.h"
#include "mazetraverser.h"
#include "micromouse.h"
#include "painter.h"
#include "tile.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <iostream>

#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::cout<< " before set lefts " <<  std::endl;
    QGraphicsScene * scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);


    Micromouse * micromouse = new Micromouse();
    micromouse->setPos(x(), y());
    scene->addItem(micromouse);



    timer->start(200);


    MazeTraverser * mazeTraverser = new MazeTraverser();
    setMazeTraverser(*mazeTraverser);

    QVector<QString> data = FileUtils::readFile();
    Maze *maze = new Maze();
    maze->createMaze(data);

    TurnLeftStrategy turnLeftStrategy;
    turnLeftStrategy.setMaze(maze);
    turnLeftStrategy.setMicromouse(micromouse);

    mazeTraverser->setMicromouse(micromouse);
    mazeTraverser->setMaze(maze);



    Painter painter;
    for(int x = 0; x < maze->getColumns(); x++) {
        for(int y = 0; y < maze->getColumns(); y++) {
            Tile tile = maze->getMap()[x][y];
            for(Direction d : tile.getWalls()) {
                QGraphicsLineItem * line = painter.drawLine(x, y, 50, d);
                scene->addItem(line);
            }
        }
    }

    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMazeTraverser(MazeTraverser &_mazeTraverser)
{
    mazeTraverser = &_mazeTraverser;
}

void MainWindow::reset()
{
    MazeTraverser * mazeTraverser = new MazeTraverser();
    setMazeTraverser(*mazeTraverser);

    QVector<QString> data = FileUtils::readFile();
    Maze *maze = new Maze();
    maze->createMaze(data);

    Micromouse * micromouse = new Micromouse();
    micromouse->setPos(x(), y());
    mazeTraverser->setMicromouse(micromouse);
    mazeTraverser->setMaze(maze);
    ui->graphicsView->scene()->addItem(micromouse);
}

void MainWindow::refreshMovesCount()
{
    ui->label_2->setText(QString::number(mazeTraverser->getMovesCount()));
}


void MainWindow::on_pushButton_clicked()
{

}


void MainWindow::on_pushButton_toggled(bool checked)
{
    if(checked) {
        ui->pushButton->setText("Stop");
        mazeTraverser->startTraversing();
        connection = connect(timer, SIGNAL(timeout()), this, SLOT(refreshMovesCount()));
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
    } else {
        ui->pushButton->setText("Start");
        mazeTraverser->stopTraversing();
        disconnect(connection);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
    }
}


void MainWindow::on_pushButton_2_toggled(bool checked)
{
    mazeTraverser->setStrategy(1);
}


void MainWindow::on_pushButton_3_toggled(bool checked)
{
    mazeTraverser->setStrategy(2);
}


void MainWindow::on_resetButton_clicked()
{
    reset();
}

