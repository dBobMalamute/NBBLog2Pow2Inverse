import QtQuick 2.12
import QtQuick.Controls 2.12

ToolBar
{
    id: palleteBar
    height: 46
    width: 4 + (palleteListView.count * 44);
    background: Rectangle
    {
        anchors.fill: parent
        color: "#333333";
        border.color: "black"
        border.width: 2
    }
    ComboBox
    {
        id: ideaCollectionComboBox
        editable: false
        width: 0
        height: 60
        opacity: 0.0
        enabled: false

        model: malamuteHandler.collectionList
        onActivated:
        {
            malamuteHandler.setPalleteList(currentValue)
        }
        Component.onCompleted:
        {
            malamuteHandler.setPalleteList(currentValue);
        }
    }

    ListView
    {
        id: palleteListView
        height: parent.height
        interactive: false
        clip: true
        anchors.left: parent.left
        anchors.leftMargin: 4
        anchors.top: parent.top
        anchors.right: parent.right
        orientation: ListView.Horizontal
        model: malamuteHandler.paletteList
        spacing: 4
        delegate: PaletteItem
        {

        }
    }
}
