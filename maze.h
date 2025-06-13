#ifndef MAZE_H
#define MAZE_H

#include "qobject.h"
#include <vector>
#include <tile.h>


/*!
 * \brief The Maze class
 * Klasa reprezentujaca plansze
 */
class Maze
{
private:
    int columns = 0;
    int rows = 0;
    int centerColumn = 4;
    int centerRow = 2;
    std::vector<std::vector<Tile>> mapTap;
    Tile * currentTile;
    int currentX;
    int currentY;
    bool isOnStaringTile = true;
public:
    Maze();

    /*!
     * Metoda pobierajaca kafelek po wspolrzednych
     * \brief getTile
     * \param col - wspolrzedna x
     * \param row - wspolrzedna y
     * \return
     */
    Tile getTile(int col, int row);


    int getColumns();
    int getRows();

    //tworzy plansze z danych wczytanych z pliku
    void createMaze(QVector<QString> data);
    std::vector<std::vector<Tile>> getMap();

    //wspolrzedna x na ktorej obecnie znajduje sie robot
    int getCurrentX();

    //wspolrzedna y na ktorej obecnie znajduje sie robot
    int getCurrentY();

    void setCurrentX(int _x);
    void setCurrentY(int _y);

    //kafelek na ktorym obecnie znajduje sie robot
    Tile * getCurrentTile();
    void updateCurrentTile(Tile tile);
    void isNotOnStartingTile();
    bool getIsOnStartingTile();

    //wspolrzedna x punktu koncowego
    int getCenterColumn();

    //wspolrzedna y punktu koncowego
    int getCenterRow();
};

#endif // MAZE_H
