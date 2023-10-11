#include "LogarithmBase2Idea.h"
#include <cmath>

LogarithmBase2Attributes::LogarithmBase2Attributes()
{
    m_listName = "Logarithm Base 2";
    m_displayName = "Logarithm\nBase 2";
    m_authors << "dBob";
    m_description = "Calculates the logarithm base 2 of the inputted number";
    m_iconPath = "qrc:/Icons/LogarithmBase2.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_dataTypesOut.push_back(Magic<NumberDataTypeAttributes>::cast().id());

    m_embeddedQMLPath = ":/QML/LogarithmBase2Minimized.qml";

    m_gear = true;
}


LogarithmBase2Idea::LogarithmBase2Idea()
{

}

const IdeaAttributes LogarithmBase2Idea::attributes()
{
    return Magic<LogarithmBase2Attributes>::cast();
}

void LogarithmBase2Idea::validate()
{
    auto n1 = m_input.lock();
    if(n1)
    {
        if(n1->number() > 0.0)
        {
            setStatus(IdeaStatus::Working, "Logging", "Currently calcuating the log base 2 of " + QString::number(n1->number()));
            compute(n1->number());
        }
        else if(qFuzzyIsNull(n1->number()))
        {
            setStatus(IdeaStatus::Error, "Negative Infinity", "The logarithm of a non-positive number is an imaginary number. Imaginary numbers are not currently supported");
        }
        else
        {
            setStatus(IdeaStatus::Error, "Imaginary Answer", "The logarithm of a non-positive number is an imaginary number. Imaginary numbers are not currently supported");
            emit clear();
        }
    }
    else
    {
        setDefaultStatus();
        emit clear();
    }
}

void LogarithmBase2Idea::compute(double n1)
{
    emit startSpinningGear();

    double log = log2(n1);

    m_result = std::make_shared<NumberDataType>(log);
    emit newData(0);

    setupDisplay();

    emit stopSpinningGear();
}
