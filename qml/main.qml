import QtQuick 2.6
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2

import Qt.labs.controls 1.0

import Ultrabot.Core 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Ultrabot")

    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            ToolButton {
                text: "Open"
                onClicked: {
                    fileDialog.folder = render.path;
                    fileDialog.open();
                }

                FileDialog {
                    id: fileDialog
                    title: "Please choose a RAW photo file"
                    onAccepted: {
                        render.source = fileDialog.fileUrls[0];
                    }
                }
            }
        }
    }

    Flickable {
        id: container
        anchors.fill: parent

        contentWidth: render.width
        contentHeight: render.height

        ImageRender {
            id: render
            viewportSize {
                width: container.width
                height: container.height
            }
        }

        ScrollBar.vertical: ScrollBar {}
        ScrollBar.horizontal: ScrollBar {}
    }

}
