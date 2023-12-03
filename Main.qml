import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import qnavi

Window {
    width: 640
    height: 480
    visible: true
    title: "Hello World"

    NaviAuthenticator {
        id: na
        server: server.text
        user: user.text
        password: password.text
    }

    ColumnLayout {
        width: parent.width
        Label {
            Layout.alignment: Qt.AlignHCenter
            id: serverLabel
            text: "Server"
        }
        TextField {
            Layout.alignment: Qt.AlignHCenter
            id: server
        }

        Label {
            Layout.alignment: Qt.AlignHCenter
            id: userLabel
            text: "Username"
        }
        TextField {
            Layout.alignment: Qt.AlignHCenter
            id: user
        }
        Label {
            Layout.alignment: Qt.AlignHCenter
            id: passwordLabel
            text: "Password"
        }
        TextField {
            Layout.alignment: Qt.AlignHCenter
            id: password
        }
        Button {
            Layout.alignment: Qt.AlignHCenter
            text: "Log in"
            onClicked: {
                na.getRequest()
            }
        }
    }
}
