import QtQuick 2.15
import QtQuick.Controls 2.15 as Controls

import org.kde.kirigami 2.20 as Kirigami
import org.kde.kcm 1.2 as KCM

KCM.SimpleKCM {
    implicitHeight: 500

    Kirigami.FormLayout {
        Controls.Button {
            Kirigami.FormData.label: "This writes the time to the kcmtimerc config file."
            text: kcm.config.width
        }
    }
}
