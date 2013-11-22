#ifndef BUTTONMOUSE_H
#define BUTTONMOUSE_H

#include <QObject>
#include <QtCore>
#include <QCursor>
#include <QGuiApplication>
#include <QMouseEvent>
#include <QQuickItem>

class ButtonMouse: public QObject
{
    Q_OBJECT

public:
    ButtonMouse(QQuickItem* gui, QCursor* cursor);

public slots:
    void Button1Slot();
    void Button2Slot();
    void Button3Slot();
    void Button4Slot();

private:
    QCursor* cursor;
    QQuickItem* gui;
};

#endif // BUTTONMOUSE_H
