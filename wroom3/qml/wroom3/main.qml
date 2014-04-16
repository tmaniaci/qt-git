import QtQuick 2.1
import QtQuick.Controls 1.0

ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480

    Text {
            text: "hello"
            anchors.centerIn: parent
        }

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    ListModel {
       id: libraryModel
       ListElement{ title: "<b>A Masterpiece</b>" ; author: "Gabriel" }
       ListElement{ title: "Brilliance"    ; author: "Jens" }
       ListElement{ title: "Outstanding"   ; author: "Frederik" }
    }

    TableView {
       TableViewColumn{ role: "title"  ; title: "Title" ; width: 100 }
       TableViewColumn{ role: "author" ; title: "Author" ; width: 200 }
       model: libraryModel
    }

}
