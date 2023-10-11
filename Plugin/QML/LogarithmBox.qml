import QtQuick 2.12

Item
{
    id: root
    property int boxNumber: 0;
    property int borderWidth: 0
    property rect tileRect : Qt.rect(1,1,1,1)
    property double delay: 1000;
    opacity: 0.0

    width: 60
    height: 40

    Rectangle
    {
        id: tile;
        color: idea.inPortLabelColors[0]
        border.color: Qt.darker(idea.inPortLabelColors[0]);
        border.width: borderWidth;
        width: tileRect.width;
        height: tileRect.height;
        x: tileRect.x;
        y: tileRect.y;
    }
    Rectangle
    {
        id: shadow;
        color: idea.inPortLabelColors[0]
        border.color: Qt.darker(idea.inPortLabelColors[0]);
        border.width: borderWidth;
        width: tileRect.width;
        height: tileRect.height;
        x: tileRect.x;
        y: tileRect.y;
        opacity: 0.3
    }

    function maybeFadeOut(removeAbove)
    {
        if(removeAbove < boxNumber)
            fadeOutAnimation.start();
    }

    SequentialAnimation
    {
        id: creationAnimation
        running: true;
        PauseAnimation{duration: delay}
        PropertyAction {target: root; property: "opacity"; value: 1.0 }
    }

    SequentialAnimation
    {
        id: fadeOutAnimation

        PropertyAnimation
        {
            target: tile
            property: "color"
            to: idea.outPortLabelColors[0]
            duration: 500
        }
        ParallelAnimation
        {
            NumberAnimation
            {
                target: tile
                property: "opacity"
                to: 0.0;
                duration: 2500
                easing.type: Easing.OutQuad
            }
            NumberAnimation
            {
                target: tile
                properties: "width,height"
                to: 0.0;
                duration: 2500
                easing.type: Easing.OutQuad
            }
            NumberAnimation
            {
                target: tile
                property: "x"
                to: tile.x + tile.width;
                duration: 2500
                easing.type: Easing.OutQuad
            }
        }
    }
}
