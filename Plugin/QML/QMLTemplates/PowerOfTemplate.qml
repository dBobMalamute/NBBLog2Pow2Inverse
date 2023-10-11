import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12

import "../PowerHelperFunctions.js" as HelperFunctions

Item
{
    id: root
    width: 544
    height: 240

    property real powerOf : 2.0
    property real inputNumber: 0.0;
    property real outputNumber: 0.0;
    property real currentlyShownBoxes: 1.0;
    property real multiplications: 0.0;
    property real fraction: 0.0;
    property alias powerOfNumber : root.powerOf;
    property alias multiplyByBottonText: multiplyByButton.text

    Component.onCompleted:
    {
        HelperFunctions.setupActionPicture(powerOf);
    }

    Connections
    {
        target: idea
        function onDisplay(input, output)
        {
            HelperFunctions.clearBoxes();
            inputNumber = input;
            outputNumber = output;
            currentlyShownBoxes = 1.0;
            multiplications = 0.0;
            fraction = input % 1;

            inputText.text = "0 of " + parseFloat(input.toPrecision(4));
            if(output <= 10000 && input > 0)
            {
                HelperFunctions.setupActionPicture(powerOf);
                HelperFunctions.setupForBoxes(output);
                multiplyBy.enabled = true
                resetButton.enabled = true
                outputText.text = 1.0;
                animationUnsupportedText.visible = false;
            }
            else
            {
                multiplyBy.enabled = false;
                resetButton.enabled = false;
                outputText.text = parseFloat(outputNumber.toPrecision(4))
                animationUnsupportedText.visible = true;
            }
        }

        function onClear()
        {
            animationUnsupportedText.visible = false;
            inputText.text = "";
            outputText.text = "";
            currentlyShownBoxes = 0.0;
            multiplications = 0.0;
            fraction = 0.0;
            HelperFunctions.clearBoxes();
        }
    }

    Rectangle
    {
        id: inputArea
        anchors.left: parent.left
        height: parent.height
        width: 64
        gradient: Gradient
        {
            GradientStop{position: 0.0; color: "black"}
            GradientStop{position: 0.5; color: "#282828"}
            GradientStop{position: 1.0; color: "black"}
        }

        Image
        {
            id: actionPicture
            anchors.centerIn: parent
            fillMode: Image.PreserveAspectFit
            width: 64
            source: "qrc:/Images/UpArrows.png"

            Item
            {
                id: topRectanglesContainer
                width: 64
                height: 20
                y: 14
            }

            Item
            {
                id: midRectanglesContainer
                width: 64
                height: 20
                y: 51
            }

            Item
            {
                id: botRectanglesContainer
                width: 64
                height: 20
                y: 82
            }
        }

        Text
        {
            anchors.top: actionPicture.bottom
            anchors.topMargin: 4
            id: inputText
            text: "";
            color: idea.inPortLabelColors[0]
            font.pointSize: 12
            font.family: "verdana"
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    Rectangle
    {
        id: outputArea
        anchors.right: parent.right
        height: parent.height
        width: 64
        gradient: Gradient
        {
            GradientStop{position: 0.0; color: "black"}
            GradientStop{position: 0.5; color: "#282828"}
            GradientStop{position: 1.0; color: "black"}
        }

        Rectangle
        {
            id: outputBox
            anchors.centerIn: parent
            width: 60
            height: 60
            color: idea.outPortLabelColors[0]
            border.width: 6
            border.color: Qt.darker(idea.outPortLabelColors[0]);
        }

        Text
        {
            id: outputText
            anchors.top: outputBox.bottom
            anchors.topMargin: 4
            anchors.horizontalCenter: parent.horizontalCenter
            y: 190
            color: idea.outPortLabelColors[0]
            font.pointSize: 16
            font.family: "verdana"
        }
    }

    Rectangle
    {
        width: 408
        height: 208
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#050512"
        radius: 4
    }

    Item
    {
        id: animationArea
        y: 4
        width: 400
        anchors.horizontalCenter: parent.horizontalCenter
        height: 200
    }

    Item
    {
        id: fractionAnimationArea
        anchors.fill: animationArea;
    }

    Text
    {
        id: animationUnsupportedText;
        text: "Animation Unsupported";
        horizontalAlignment: Text.AlignHCenter
        color: "white"
        font.bold: true;
        font.pointSize: 10
        anchors.centerIn: animationArea
        visible: false
    }

    function multiplyBy()
    {
        if(powerOf*currentlyShownBoxes <= outputNumber)
        {
            currentlyShownBoxes *= powerOf;
            multiplications += 1;
            inputText.text = multiplications + " of " + parseFloat(inputNumber.toPrecision(4));
            outputText.text = parseFloat(currentlyShownBoxes.toPrecision(4));
            HelperFunctions.addBoxesWithFraction(currentlyShownBoxes);
        }
        else if(currentlyShownBoxes < outputNumber)
        {
            currentlyShownBoxes = outputNumber;
            multiplications = inputNumber;
            inputText.text = parseFloat(inputNumber.toPrecision(4)) + " of " + parseFloat(inputNumber.toPrecision(4));

            outputText.text = parseFloat(currentlyShownBoxes.toPrecision(4));
            HelperFunctions.addBoxesWithFraction(currentlyShownBoxes);
        }
    }

    Rectangle
    {
        id: controlsRow
        width: buttonsRow.width + 10 //Row is width: 286
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        height: 34

        radius: 4
        color: "#050512"

        Row
        {
            id: buttonsRow
            x: 5
            spacing: 6

            Button
            {
                id: multiplyByButton
                height: 32
                anchors.verticalCenter: parent.verticalCenter;
                onClicked:
                {
                    multiplyBy();
                }
                Material.background: idea.inPortLabelColors[0]
                font.family: "verdana"
                font.bold: true;
                font.pointSize: 12
                Material.foreground:  "#1a1a1a"
                font.capitalization: Font.MixedCase
            }
            Button
            {
                id: resetButton
                height: 32
                text: "Reset"
                anchors.verticalCenter: parent.verticalCenter;
                onClicked:
                {
                    HelperFunctions.clearBoxes();
                    currentlyShownBoxes = 1;
                    multiplications = 0.0;
                    inputText.text = "0 of " + parseFloat(inputNumber.toPrecision(4));

                    outputText.text = "1";
                    HelperFunctions.setupForBoxes(outputNumber);
                }
                font.capitalization: Font.MixedCase
                font.family: "verdana"
                font.bold: true;
                font.pointSize: 12
                Material.background: Material.Grey
                Material.foreground:  "#1a1a1a"
            }
        }
    }
}
