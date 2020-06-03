import QtQuick 2.12
//import QtQuick.Window 2.12
import Qt.labs.calendar 1.0
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3


Item {
    visible: true
    width: 640
    height: 480



    RowLayout {
        id: rowLayout
        height: 100
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top

        TextField {
            id: textIpPort
            text: qsTr("192.168.0.164")
            Layout.fillWidth: true
            // onTextChanged: sdd;
        }

        SpinBox {
            id: spinBox
            editable: true
            value: 4242
            to: 65532
            from: 10
            Layout.fillWidth: true
        }


        Button {
            id: buttonIpPort
            text: qsTr("ButtonIp")
            Layout.fillWidth: true
            onClicked: cpp.connectToServer(textIpPort.text,spinBox.value)
        }


    }



}

/*##^##
Designer {
    D{i:1;anchors_height:100;anchors_width:100;anchors_x:188;anchors_y:131}
}
##^##*/
