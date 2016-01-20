import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
	title: qsTr("ACM")
    width: 640
    height: 480
    visible: true

	Item {
		id: main
		anchors.fill: parent

		Label {
			id: lbl1
			width: 100
			height: 40
			text: dbClass.teamNumber[0]
		}

		Label {
			id: lbl2
			width: 100
			height: 40
			text: dbClass.teamName[0]
			anchors.top: lbl1.bottom
		}

		Button {
			width: 100
			height: 40
			anchors.centerIn: parent
            text: "Print"
			onClicked: dbClass.changeTeamName()
		}
	}
}
