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
            onClicked: status.text = "Button 1"
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
            onClicked: status.text = "Button 2"
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
            onClicked: status.text = "Button 3"
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
            onClicked: status.text = "Button 4"
        }
    }
}
