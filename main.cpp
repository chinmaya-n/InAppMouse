#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "Leap/LeapListener.h"
#include <QQuickItem>
#include <memory>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Viewer & Custom Cursor
    QCursor cursor(Qt::ArrowCursor);
    QtQuick2ApplicationViewer viewer;
    viewer.setCursor(cursor);
    viewer.setMainQmlFile(QStringLiteral("qml/MouseSimulation/main.qml"));
    std::shared_ptr<QQuickItem> root(viewer.rootObject());
    // Run QML File
//    viewer.showExpanded();
    viewer.showFullScreen();

    // Leap Initialization
    Controller controller;
    LeapListener listener(root.get(), &cursor);
    controller.addListener(listener);

    // Connect Signals-Slots
    QObject::connect(&listener, SIGNAL(signalKeyTap(float, float)), &viewer, SLOT(mouseClick(float, float)));

    return app.exec();
}
