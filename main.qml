import QtQuick 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.11
import QtQuick.Extras 1.4




Item {                                                          //Un item est nécessaire plus qu'un une Window
    id: window
    visible: true
    width: 640
    height: 480

    property color rectColor: "blue"

    //    title: qsTr("Hello World")





    RowLayout {
        id: rowLayout
        y: 0
        height: window.height*0.2
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0


        Text {
            id: texteServeur
            text: qsTr("Serveur")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillWidth: true
            font.pixelSize: 12
        }

    }


    GridLayout {
        id: gridLayout
        anchors.bottomMargin: window.height*0.5
        visible: true
        layoutDirection: Qt.LeftToRight
        flow: GridLayout.LeftToRight
        columns: 2
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.top: rowLayout.bottom
        anchors.topMargin: 0


        TextArea {
            objectName: "sensorLuxValue"
            id: textAreaLux
            x: gridLayout.width*0.02
            y: gridLayout.height*0.05
            width: 320
            height: 41
            text: "détection ? "
            visible: true
            Layout.fillHeight: true
            Layout.fillWidth: true
            wrapMode: Text.WordWrap
        }

        TextArea {
            objectName: "sensorSoundValue"
            id: textAreaSound
            x: 320
            y: gridLayout.height*0.05
            width: 320
            height: 41
            text: "détection ?"
            clip: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillHeight: true
            Layout.fillWidth: true
            wrapMode: Text.WordWrap
        }



    }

    StatusIndicator {
        id: statusIndicator
        objectName: "luxIndicator"
        x: window.width*0.35
        y: window.height*0.2
        active: false
    }

    StatusIndicator {
        id: statusIndicator1
        objectName: "soundIndicator"
        x: window.width*0.85
        y: window.height*0.2
        active: false

    }




}


















/*Timer{
    id : timer
    running : true
    interval : 3000
    repeat : true
    //onTriggered:  console.log("message de test"+ textInput.width)
    onTriggered: testTexte.append("test toutes les 3s");
}*/

/*##^##
Designer {
    D{i:2;anchors_x:292;anchors_y:32}D{i:3;anchors_height:100;anchors_width:100;anchors_x:238;anchors_y:177}
}
##^##*/
