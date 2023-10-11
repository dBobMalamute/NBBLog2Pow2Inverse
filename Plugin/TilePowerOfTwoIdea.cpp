#include "TilePowerOfTwoIdea.h"
#include <cmath>

TilePowerOfTwoAttributes::TilePowerOfTwoAttributes()
{
    m_listName = "Tile Power of 2";
    m_displayName = "Power of 2";
    m_authors << "dBob";
    m_description = "This idea calculates 2 to the inputted number.";
    m_iconPath = "qrc:/Icons/PowerOfTwo.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_embeddedQMLPath = ":/QML/TilePowerOfTwoIdea.qml";

    m_minimizedQMLPath = ":/QML/PowerOfTwoMinimized.qml";
    m_minimizable = true;

    m_gear = true;
}

TilePowerOfTwoIdea::TilePowerOfTwoIdea()
{

}

const IdeaAttributes TilePowerOfTwoIdea::attributes()
{
    return Magic<TilePowerOfTwoAttributes>::cast();
}

void TilePowerOfTwoIdea::resetDisplay()
{
    if(valid())
    {
        double n = m_input.lock()->number();
        double exp = std::exp2(n);
        emit display(n, exp);
    }
}

