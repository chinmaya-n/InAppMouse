import QtQuick 2.0

Rectangle {
    width: 500
    height: 400
    color: "black"

    Text {
        id: status
        text: qsTr("Hello World")
        color: "red"
        anchors.centerIn: parent
    }

    MouseArea {
        width: parent.width/2
        height: parent.height/2
        anchors.centerIn: parent
        hoverEnabled: true
        onClicked: {
            if(status.text != "Center clicked!")
                status.text = "Center clicked!"
            else
                status.text = "Hello World"
        }

        Rectangle {
            id: borderRect
            anchors.fill: parent
            color: "transparent"
            border.width: 2
            border.color: "white"
        }
    }

    Rectangle {
        id: button1
        width: 100
        height: 50
        color: "lightblue"

        Text {
            text: "Button 1"
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onClicked: status.text = "Button 1"
            onEntered: parent.color = "white"
            onExited: parent.color = "lightblue"
        }
    }

    MouseArea {
        id: button1a
        width: 100
        height: 50
        hoverEnabled: true
        anchors.top: button1.bottom
        anchors.left: parent.left
        onClicked: status.text = "clicked button-1a"
        onEntered: status.text = "entered button-1a"
        onExited: status.text = "exited button-1a"

        Rectangle {
            anchors.fill: parent
            border.color: "white"
            border.width: 1
        }
    }

    Rectangle {
        id: button2
        width: 100
        height: 50
        color: "lightblue"
        anchors.right: parent.right
        anchors.top: parent.top

        Text {
            text: "Button 2"
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onClicked: status.text = "Button 2"
            onEntered: parent.color = "white"
            onExited: parent.color = "lightblue"
        }
    }

    Rectangle {
        id: button3
        width: 100
        height: 50
        color: "lightblue"
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        Text {
            text: "Button 3"
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onClicked: status.text = "Button 3"
            onEntered: parent.color = "white"
            onExited: parent.color = "lightblue"
        }
    }

    Rectangle {
        id: button4
        width: 100
        height: 50
        color: "lightblue"
        anchors.left: parent.left
        anchors.bottom: parent.bottom

        Text {
            text: "Button 4"
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onClicked: status.text = "Button 4"
            onEntered: parent.color = "white"
            onExited: parent.color = "lightblue"
        }
    }
}
