#ifndef LEAPLISTENER_H
#define LEAPLISTENER_H


#include "Leap.h"
using namespace Leap;
#include <QObject>
#include <QtCore>
#include <QQuickItem>
#include <QtGui/QGuiApplication>
#include <QCursor>
#include <math.h>

class LeapListener : public QObject, public Listener
{
    Q_OBJECT

public:
    LeapListener(QQuickItem*, QCursor*);
    void movePointer(float x, float y, int64_t time);
    virtual void onConnect(const Controller &);
    virtual void onFrame(const Controller &);

private:
    Frame previousFrame;
    Frame currentFrame;
    QQuickItem* gui;
    QCursor* cursor;
    int screenWidth;
    int screenHeight;
    float x, y, oldX, oldY;
    int64_t lastMoveTime;
    bool activeWindow;

signals:
    void signalKeyTap(float, float);

public slots:
    void focusChanged();
};

#endif // LEAPLISTENER_H
