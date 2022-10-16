import QtQuick 2.15 as Quick
import QtQuick.Controls 2.15 as Controls
import QtQuick.Layouts 1.15 as Layouts
import org.kde.kirigami 2.20 as Kirigami
import kconfigxttest 1.0

Kirigami.ApplicationWindow
{
    id: app
    title: "KConfigXT test"
    width: WindowSettings.width
    height: WindowSettings.height
    onWidthChanged: {
        WindowSettings.width = app.width
    }
    onHeightChanged: {
        WindowSettings.height = app.height
    }

    Layouts.ColumnLayout {
        anchors.centerIn: parent

        Quick.Text {
            text: "Width: " + WindowSettings.width
            color: "gray"
            font.pointSize: 30
            Layouts.Layout.alignment: Qt.AlignCenter
        }
        Quick.Text {
            text: "Height: " + WindowSettings.height
            color: "gray"
            font.pointSize: 30
            Layouts.Layout.alignment: Qt.AlignCenter
        }
    }
}
