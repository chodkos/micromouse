#include <set>
#include <direction.h>
#ifndef TILE_H
#define TILE_H

/*!
 * \brief The Tile class
 * Klasa reprezentujaca pojedynczy kafelek, ktory moze byc otoczony sciankami
 */
class Tile
{
private:
    bool visited = false;
    std::set<Direction> walls;
    Tile previousTile();
    int previousX;
    int previousY;
public:
    Tile();


    void addDirection(Direction direction);

    //kolekcja zawierajaca kierunki z ktorych dany kafelek jest otoczony scianami
    std::set<Direction> getWalls();

    /*!
     * Metoda tworzy sciany do okola kafelka w podanych kierunkach
     * \param north
     * \param south
     * \param west
     * \param east
     */
    void createWalls(bool north, bool south, bool west, bool east);
    bool getVisited();
    void setVisited();
    Tile getPreviousTile();
    void setPreviousTile();

    //pobiera wspolrzedna x poprzednio odwiedzonego kafelka
    int getPreviousX();
    //pobiera wspolrzedna y poprzednio odwiedzonego kafelka
    int getPreviousY();

    //ustawia wspolrzedna x poprzednio odwiedzonego kafelka
    void setPreviousX(int _x);
    //ustawia wspolrzedna y poprzednio odwiedzonego kafelka
    void setPreviousY(int _y);
};

#endif // TILE_H
