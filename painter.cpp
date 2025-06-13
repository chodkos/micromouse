#include "painter.h"

Painter::Painter() {}

QGraphicsLineItem* Painter::drawLine(int x, int y, int length, Direction direction)
{
    QGraphicsLineItem * line = new QGraphicsLineItem();
    //zmienne w celu wizualizacji ścianek, w celu sprawdzenia czy wszystkie kafelki mają ścianki
    //np. jeśli chcemy mieć ścienakę pomiędzy dwoma kafelkami (jeden pod drugim) to górny powinien mieć ściankę na dole
    // a dolny ściankę na górze
    //bez poniższych zmiennych nie będzie widać takich braków, gdyż ścianki nakładają się na siebie
    // przykładowe wartości do tesów to np. 2 i 5
    int var1Test = 0;
    int var2Test = 0;
    switch (direction) {
    case Direction::NORTH:
        line->setLine(length*x,length*y + var2Test, length*x+length,length*y + var2Test);
        break;
    case Direction::SOUTH:
        line->setLine(length*x,length*y+length-var1Test, length*x+length,length*y+length-var1Test);
        break;
    case Direction::WEST:
        line->setLine(length*x+var2Test,length*y, length*x+var2Test,length*y+length);
        break;
    case Direction::EAST:
        line->setLine(length*x+length-var1Test,length*y, length*x+length-var1Test,length*y+length);
        break;
    default:
        break;
    }
    return line;
}
