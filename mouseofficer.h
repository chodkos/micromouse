#ifndef MOUSEOFFICER_H
#define MOUSEOFFICER_H

#include "micromouse.h"

#include <QObject>

class MouseOfficer : public QObject
{
    Q_OBJECT
public:
    explicit MouseOfficer(QObject *parent = nullptr);
    void sendMove();
    void setMicromouse(Micromouse &_micromouse);
private:
    Micromouse * micromouse;
signals:
    void moveMicromouse();
};

#endif // MOUSEOFFICER_H
