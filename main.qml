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
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillWidth: true
            font.pixelSize: 14
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
        y: window.height*0.3
        active: false
    }

    StatusIndicator {
        id: statusIndicator1
        objectName: "soundIndicator"
        x: window.width*0.85
        y: window.height*0.3
        active: false

    }

    Button {
        id: buttonArchive
        x: parent.width*0.05
        y: parent.height*0.4
        anchors.left: parent.left*0.2
        anchors.bottom: parent.top*0.2
        text: qsTr("Archive")
        onClicked: cpp.displayArchive()

    }


    SwipeView {

        id: swipeView
        objectName: "swipeArchive"
        anchors.left: buttonArchive.right
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        opacity: 0
        x: 217
        y: 135
        width: buttonArchive.right*0.9
        height: parent.height*0.60
        clip: true

        Repeater {

            model: 30

            PageArchive{

                anchors.fill: swipeView
            }

        }
    }
}




            /* delegate:   Page {
                width: swipeView.width
                height: swipeView.height

                header: Label {
                    text: qsTr("Page " + index)
                    color : "lightBlue"
                    font.pointSize: 13
                    padding: 10
                }


                Rectangle {
                    border.width: 1
                    border.color: "blue"
                    anchors.fill: parent
                    color: colorModel[i]

                }

                Label {
                    text: qsTr("You are on Page " + index)
                    anchors.centerIn: parent
                }
            }*/

















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
