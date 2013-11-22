#include "ButtonMouse.h"

ButtonMouse::ButtonMouse(QQuickItem* gui, QCursor* cursor)
{
    this->gui = gui;
    this->cursor = cursor;
}

void ButtonMouse::Button1Slot()
{
//    cursor->setPos(50, 175);

    QGuiApplication::sendEvent(gui, new QMouseEvent(QEvent::MouseButtonPress, QPointF(50, 175),
                                                    Qt::LeftButton, Qt::LeftButton, Qt::NoModifier));
    QGuiApplication::sendEvent(gui, new QMouseEvent(QEvent::MouseButtonRelease, QPointF(50, 175),
                                                    Qt::LeftButton, Qt::LeftButton, Qt::NoModifier));
}

void ButtonMouse::Button2Slot()
{
//    cursor->setPos(50, 125);

    QGuiApplication::sendEvent(gui, new QMouseEvent(QEvent::MouseButtonPress, QPointF(50, 125),
                                                    Qt::LeftButton, Qt::LeftButton, Qt::NoModifier));
    QGuiApplication::sendEvent(gui, new QMouseEvent(QEvent::MouseButtonRelease, QPointF(50, 125),
                                                    Qt::LeftButton, Qt::LeftButton, Qt::NoModifier));
}

void ButtonMouse::Button3Slot()
{
//    cursor->setPos(50, 75);

    QGuiApplication::sendEvent(gui, new QMouseEvent(QEvent::MouseButtonPress, QPointF(50, 75),
                                                    Qt::LeftButton, Qt::LeftButton, Qt::NoModifier));
    QGuiApplication::sendEvent(gui, new QMouseEvent(QEvent::MouseButtonRelease, QPointF(50, 75),
                                                    Qt::LeftButton, Qt::LeftButton, Qt::NoModifier));
}

void ButtonMouse::Button4Slot()
{
//    cursor->setPos(50, 25);

    QGuiApplication::sendEvent(gui, new QMouseEvent(QEvent::MouseButtonPress, QPointF(50, 25),
                                                    Qt::LeftButton, Qt::LeftButton, Qt::NoModifier));
    QGuiApplication::sendEvent(gui, new QMouseEvent(QEvent::MouseButtonRelease, QPointF(50, 25),
                                                    Qt::LeftButton, Qt::LeftButton, Qt::NoModifier));
    qDebug() << "in button4 slot";
}
