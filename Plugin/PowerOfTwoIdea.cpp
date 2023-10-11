#include "PowerOfTwoIdea.h"
#include <cmath>

PowerOfTwoAttributes::PowerOfTwoAttributes()
{
    m_listName = "Power of 2";
    m_displayName = "Power of 2";
    m_authors << "dBob";
    m_description = "This idea calculates 2 to the inputted number.";
    m_iconPath = "qrc:/Icons/PowerOfTwo.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_embeddedQMLPath = ":/QML/PowerOfTwoMinimized.qml";

    m_gear = true;
}

PowerOfTwoIdea::PowerOfTwoIdea()
{

}

const IdeaAttributes PowerOfTwoIdea::attributes()
{
    return Magic<PowerOfTwoAttributes>::cast();
}

void PowerOfTwoIdea::validate()
{
    auto n1 = m_input.lock();
    if(n1)
    {
        setStatus(IdeaStatus::Working, "Calculating", "Calculating 2 to the " + QString::number(n1->number()) + " power.");
        compute(n1->number());
    }
    else
    {
        setDefaultStatus();
        emit clear();
    }
}

void PowerOfTwoIdea::compute(double n1)
{
    emit startSpinningGear();

    double exp = std::exp2(n1);

    m_result = std::make_shared<NumberDataType>(exp);
    emit newData(0);

    setupDisplay();

    emit stopSpinningGear();
}

