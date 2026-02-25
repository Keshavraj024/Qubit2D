import QtQuick
import QtQuick.Controls.Material

Window {
    width: 800
    height: 800
    visible: true
    title: qsTr("Qubit2D Engine")

    color: active ? palette.active.window : palette.inactive.window




    minimumHeight: 400
    minimumWidth: 400

    onHeightChanged: console.log("window size changed")

    onClosing: console.log("Close the window")

    MouseArea  {
        anchors.fill: parent
        onPressed: function(event) {
            if(event.button === Qt.RightButton)
                console.log(event.button)
            Bridge.sendMousePress(event.x, event.y, event.button)
        }
    }

    Button {
        onPressed: Bridge.sendButtonPress("event")
    }

    // onActiveChanged: console.log("Window minimised", active)

}
