#include "mouseofficer.h"

MouseOfficer::MouseOfficer(QObject *parent)
    : QObject{parent}
{}

void MouseOfficer::sendMove()
{
    emit moveMicromouse();
}

void MouseOfficer::setMicromouse(Micromouse &_micromouse)
{
    micromouse = &_micromouse;
    connect(this, &MouseOfficer::moveMicromouse, micromouse, &Micromouse::moveX);
}
