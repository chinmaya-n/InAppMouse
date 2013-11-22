# Add more folders to ship with the application, here
folder_01.source = qml/MouseSimulation
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    Leap/LeapListener.cpp \
    ButtonMouse.cpp

# QT Extra modules
#QT += multimedia \
#    sql \
#    widgets

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

# Added Leap Motion Support
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Leap/ -lLeap
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Leap/ -lLeapd
else:unix: LIBS += -L$$PWD/Leap/ -lLeap

INCLUDEPATH += $$PWD/Leap
DEPENDPATH += $$PWD/Leap

HEADERS += \
    Leap/LeapListener.h \
    ButtonMouse.h
