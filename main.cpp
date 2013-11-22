#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
//#include "Leap/LeapListener.h"
#include "ButtonMouse.h"
#include <QQuickItem>
#include <memory>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Viewer & Custom Cursor
//    QCursor cursor(Qt::ArrowCursor);
    QtQuick2ApplicationViewer viewer;
//    viewer.setCursor(cursor);
    viewer.setMainQmlFile(QStringLiteral("qml/MouseSimulation/TryMouse.qml"));
    std::shared_ptr<QQuickItem> root(viewer.rootObject());

//    std::unique_ptr<ButtonMouse> bm(new ButtonMouse(root.get(), &cursor));

    // Run QML File
//    viewer.showExpanded();
    viewer.showFullScreen();
//    viewer.showMaximized();

    // Connect Signals-Slots
//    QObject::connect(root.get(), SIGNAL(button1pressed()), bm.get(), SLOT(Button1Slot()));
//    QObject::connect(root.get(), SIGNAL(button2pressed()), bm.get(), SLOT(Button2Slot()));
//    QObject::connect(root.get(), SIGNAL(button3pressed()), bm.get(), SLOT(Button3Slot()));
//    QObject::connect(root.get(), SIGNAL(button4pressed()), bm.get(), SLOT(Button4Slot()));
    QObject::connect(root.get(), SIGNAL(button1pressed(QVariant , QVariant)), &viewer, SLOT(mouseClick(QVariant , QVariant)));
    QObject::connect(root.get(), SIGNAL(button2pressed(QVariant , QVariant)), &viewer, SLOT(mouseClick(QVariant , QVariant)));
    QObject::connect(root.get(), SIGNAL(button3pressed(QVariant , QVariant)), &viewer, SLOT(mouseClick(QVariant , QVariant)));
    QObject::connect(root.get(), SIGNAL(button4pressed(QVariant , QVariant)), &viewer, SLOT(mouseClick(QVariant , QVariant)));

    return app.exec();
}

//int main(int argc, char *argv[])
//{
//    QGuiApplication app(argc, argv);

//    // Viewer & Custom Cursor
//    QCursor cursor(Qt::ArrowCursor);
//    QtQuick2ApplicationViewer viewer;
//    viewer.setCursor(cursor);
//    viewer.setMainQmlFile(QStringLiteral("qml/MouseSimulation/main.qml"));
//    std::shared_ptr<QQuickItem> root(viewer.rootObject());
//    // Run QML File
////    viewer.showExpanded();
//    viewer.showFullScreen();

//    // Leap Initialization
//    Controller controller;
//    LeapListener listener(root.get(), &cursor);
//    controller.addListener(listener);

//    // Connect Signals-Slots
//    QObject::connect(&listener, SIGNAL(signalKeyTap(float, float)), &viewer, SLOT(mouseClick(float, float)));
//    QObject::connect(&app, SIGNAL(focusWindowChanged(QWindow *)), &listener, SLOT(focusChanged()));

//    return app.exec();
//}
