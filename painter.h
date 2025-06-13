#ifndef PAINTER_H
#define PAINTER_H

#include <Direction.h>
#include <qgraphicsitem.h>

/*!
 * \brief The Painter class
 * Klasa odpowiedzialna za rysowanie obiektów
 */
class Painter
{
public:
    Painter();
    /*!
     * Metoda rysujaca linie
     * \param x - wspolrzedna x poczatku linii
     * \param y - wspolrzedna y poczotku linii
     * \param length - dlugosc linii
     * \param direction - kierunek w ktory skierowany bedzie koniec linii
     * \return QGraphicsLineItem
     *
     */
    QGraphicsLineItem *drawLine(int x, int y, int length, Direction direction);


    /*!
     * Metoda rysujaca kwadrat
     * \param x - wspolrzedna x
     * \param y - wspolrzedna y
     * \param size - dlugosc boku
     * \return QGraphicsRectItem
     */
    QGraphicsRectItem *drawRect(int x, int y, int size);
};

#endif // PAINTER_H
