#include "TileLogarithmBase2Idea.h"
#include <cmath>

TileLogarithmBase2Attributes::TileLogarithmBase2Attributes()
{
    m_listName = "Tile Logarithm Base 2";
    m_displayName = "Logarithm Base 2";
    m_authors << "dBob";
    m_description = "Calculates the logarithm base 2 of the inputted number";
    m_iconPath = "qrc:/Icons/LogarithmBase2.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_embeddedQMLPath = ":/QML/TileLogarithmBase2Idea.qml";
    m_minimizedQMLPath = ":/QML/LogarithmBase2Minimized.qml";
    m_minimizable = true;
    m_minimizedName = "Logarithm\nBase 2";
    m_differentNameOnMinimized = true;

    m_gear = true;
}


TileLogarithmBase2Idea::TileLogarithmBase2Idea()
{

}

const IdeaAttributes TileLogarithmBase2Idea::attributes()
{
    return Magic<TileLogarithmBase2Attributes>::cast();
}

void TileLogarithmBase2Idea::resetDisplay()
{
    if(valid())
    {
        double n = m_input.lock()->number();
        double log = std::log2(n);
        emit display(n, log);
    }
}
