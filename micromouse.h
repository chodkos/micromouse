#ifndef MICROMOUSE_H
#define MICROMOUSE_H

#include <Direction.h>
#include <QGraphicsRectItem>

/*!
 * Klasa reprezentujaca robota, ktrory przemierza labirynt
 */
class Micromouse: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Micromouse();
public slots:
    /*!
     * Metoda poruszajaca robotem w podanym kierunku
     * \param direction
     */
    void move(Direction direction);
};

#endif // MICROMOUSE_H
