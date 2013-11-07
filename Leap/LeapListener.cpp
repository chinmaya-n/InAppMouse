#include "LeapListener.h"

LeapListener::LeapListener(QQuickItem* item, QCursor* cursor)
{
    this->gui = item;
    this->cursor = cursor;
    screenWidth = item->width();
    screenHeight = item->height();

    currentFrame = previousFrame = Frame::invalid();
}

void LeapListener::movePointer(float x, float y, int64_t time)
{
    if(time-lastMoveTime > 500000)
    {
        if(abs(x-oldX)>100 && abs(y-oldY)>100)
        {
            cursor->setPos(x, y);
            oldX = x; oldY = y;
            lastMoveTime = time;
        }
    }
    else
    {
        cursor->setPos(x, y);
        if(abs(x-oldX) > 2)
            lastMoveTime = time;
        oldX = x; oldY = y;
    }
}

void LeapListener::onConnect(const Controller &controller)
{
    controller.enableGesture(Gesture::TYPE_KEY_TAP);
}

void LeapListener::onDisconnect(const Controller &controller)
{
    qDebug() << controller.isGestureEnabled(Gesture::TYPE_KEY_TAP);
}

void LeapListener::onFrame(const Controller &controller)
{
    previousFrame = currentFrame;
    currentFrame = controller.frame();

    // Move Mouse
    if(currentFrame.fingers().count() > 0)
    {
        if(currentFrame.fingers().frontmost().isValid())
        {
            Vector finger = currentFrame.interactionBox().normalizePoint(
                        currentFrame.fingers().frontmost().stabilizedTipPosition());
            x = finger.x * screenWidth;
            y = screenHeight - finger.y * screenHeight;
            movePointer(x, y, currentFrame.timestamp());
        }
    }

    // Key-Tap
    for(int i=0; i < currentFrame.gestures(previousFrame).count(); i++)
    {
        Gesture g = currentFrame.gestures()[i];

        // Error-1:
        // Mouse click will be send only to the `first click position`
        // in real, Even though we click at any other location.
        // It tries to click at our desired location, but click will be done
        // at the `first mouse click position`. It will only gets back to normal
        // only after a manual mouse click on someother location.

        if(g.isValid() && g.state() == Gesture::STATE_STOP)
        {
            if(g.type() == Gesture::TYPE_KEY_TAP)
            {
                // Key-Tap found
                signalKeyTap(oldX, oldY);
                qDebug() << "KeyTap: " << x << ", "<< y;
            }
        }
    }
}
