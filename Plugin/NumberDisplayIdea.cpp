#include "NumberDisplayIdea.h"
#include "NumberDataType.h"

NumberDisplayAttributes::NumberDisplayAttributes()
{
    m_listName = "Number Display";
    m_displayName = "";
    m_authors << "dBob";
    m_description = "Displays a single number";
    m_iconPath = "qrc:/Icons/NumberDisplay.png";

    m_dataTypesIn.push_back(Magic<NumberDataTypeAttributes>::cast().id());
    m_labelsIn << "";
    m_customLabels = true;

    m_embeddedQMLPath = ":/QML/NumberDisplayMinimized.qml";
}

NumberDisplayIdea::NumberDisplayIdea()
{
    setStatus(IdeaStatus::Working,"","Awaiting Input");
}

const IdeaAttributes NumberDisplayIdea::attributes()
{
    return Magic<NumberDisplayAttributes>::cast();
}

void NumberDisplayIdea::onNewDataIn(std::shared_ptr<DataType> data, int)
{
    auto numberData = std::dynamic_pointer_cast<NumberDataType>(data);

    if (numberData)
    {
        setStatus(IdeaStatus::Working, "Displaying", "Currently displaying the number " + QString::number(numberData->number()));
        emit displayNumber(QString::number(numberData->number()));
    }
    else
    {
        setStatus(IdeaStatus::Working,"","Awaiting Input");
        emit clearDisplay();
    }
}


