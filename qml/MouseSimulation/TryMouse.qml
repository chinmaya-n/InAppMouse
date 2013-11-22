import QtQuick 2.0

Rectangle {
    width: 500
    height: 500
    color: "black"

    property string statusText: "Status Text";
    signal button1pressed(var x, var y);
    signal button2pressed(var x, var y);
    signal button3pressed(var x, var y);
    signal button4pressed(var x, var y);

    Rectangle {
        id: button1
        width: 100
        height: 50
        anchors.left: parent.left
        anchors.top: parent.top
        color: "lightgreen"
        border.color: "red"
        border.width: 1

        Text {
            anchors.centerIn: parent
            text: "Click Me!"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                statusText = "button1 pressed"
                console.log("Mouse button1 press")
                button1pressed(150, 25)
            }
        }
    }
    Rectangle {
        id: button2
        width: 100
        height: 50
        anchors.left: parent.left
        anchors.top: button1.bottom
        color: "lightgreen"
        border.color: "red"
        border.width: 1

        Text {
            anchors.centerIn: parent
            text: "Click Me!"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                statusText = "button2 pressed"
                console.log("Mouse button2 press")
                button2pressed(150, 75)
            }
        }
    }
    Rectangle {
        id: button3
        width: 100
        height: 50
        anchors.left: parent.left
        anchors.top: button2.bottom
        color: "lightgreen"
        border.color: "red"
        border.width: 1

        Text {
            anchors.centerIn: parent
            text: "Click Me!"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                statusText = "button3 pressed"
                console.log("Mouse button3 press")
                button3pressed(150, 125)
            }
        }
    }
    Rectangle {
        id: button4
        width: 100
        height: 50
        anchors.left: parent.left
        anchors.top: button3.bottom
        color: "lightgreen"
        border.color: "red"
        border.width: 1

        Text {
            anchors.centerIn: parent
            text: "Click Me!"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                statusText = "button4 pressed"
                console.log("Mouse button4 press")
                button4pressed(150, 175)
            }
        }
    }

    Rectangle {
        id: button1sync
        width: 100
        height: 50
        anchors.left: button1.right
        anchors.top: button1.top
        color: "transparent"
        border.color: "red"
        border.width: 1

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("button1sync clicked")
            }
        }
    }
    Rectangle {
        id: button2sync
        width: 100
        height: 50
        anchors.left: button2.right
        anchors.top: button2.top
        color: "transparent"
        border.color: "red"
        border.width: 1

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("button2sync clicked")
            }
        }
    }
    Rectangle {
        id: button3sync
        width: 100
        height: 50
        anchors.left: button3.right
        anchors.top: button3.top
        color: "transparent"
        border.color: "red"
        border.width: 1

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("button3sync clicked")
            }
        }
    }
    Rectangle {
        id: button4sync
        width: 100
        height: 50
        anchors.left: button4.right
        anchors.top: button4.top
        color: "transparent"
        border.color: "red"
        border.width: 1

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("button4sync clicked")
            }
        }
    }

    Text {
        id: status
        anchors.centerIn: parent
        color: "white"
        text: statusText
    }
}
