import QtQuick 2.12

Rectangle
{
    id: root
    opacity: 0.01
    property int borderWidth: 2;
    property double finalWidth: 0
    property double finalHeight: 0;

    width: 0
    height: 0
    color: idea.inPortLabelColors[0];
    border.color: Qt.darker(idea.outPortLabelColors[0]);
    border.width: borderWidth;

    SequentialAnimation
    {
        id: fadeInAnimation
        running: true;

        ParallelAnimation
        {
            NumberAnimation
            {
                target: root
                property: "opacity"
                to: 1.0;
                duration: 2500
            }
            NumberAnimation
            {
                target: root
                property: "width"
                to: finalWidth;
                duration: 2500
            }
            NumberAnimation
            {
                target: root
                property: "height"
                to: finalHeight;
                duration: 2500
            }
        }

        PropertyAnimation
        {
            target: root
            property: "color"
            to: idea.outPortLabelColors[0]
            duration: 1000
        }
    }

    function startFadeOutAnimation()
    {
        fadeOutAnimation.start();
    }
    SequentialAnimation
    {
        id: fadeOutAnimation
        PauseAnimation {duration: 2500}
        ScriptAction
        {
            script: root.destroy();
        }
    }
}
