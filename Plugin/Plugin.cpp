#include "Plugin.h"

#include "NumberDataType.h"
#include "NumberDisplayIdea.h"
#include "TileLogarithmBase2Idea.h"
#include "TilePowerOfTwoIdea.h"
#include "NumberInputIdea.h"

QString Plugin::PluginName()
{
    return "PLUGIN";
}

QStringList Plugin::authors()
{
    return QStringList("dBob");
}

QString Plugin::PluginDescription()
{
    return "";
}

void Plugin::registerIdeas(std::shared_ptr<IdeaRegistry> ideaRegistry)
{
    ideaRegistry->registerIdea<NumberDisplayIdea>();
    ideaRegistry->registerIdea<TileLogarithmBase2Idea>();
    ideaRegistry->registerIdea<TilePowerOfTwoIdea>();
    ideaRegistry->registerIdea<NumberInputIdea>();

    qmlRegisterType(QUrl("qrc:/QML/QMLTemplates/OneToOneTemplate.qml"), "com.malamute.calculator", 1, 0, "OneToOneTemplate");
    qmlRegisterType(QUrl("qrc:/QML/QMLTemplates/LogarithmTemplate.qml"), "com.malamute.calculator", 1, 0, "LogarithmTemplate");
    qmlRegisterType(QUrl("qrc:/QML/QMLTemplates/PowerOfTemplate.qml"), "com.malamute.calculator", 1, 0, "PowerOfTemplate");

}

void Plugin::registerDataTypeAttributes(std::shared_ptr<DataTypeRegistry> dataTypeRegistry)
{
    dataTypeRegistry->registerDataTypeAttributes<NumberDataTypeAttributes>();
}

void Plugin::registerToolbars(std::shared_ptr<ToolbarRegistry> toolbarRegistry)
{
    QStringList orderList;
    orderList << Magic<NumberInputAttributes>::cast().listName();
    orderList << Magic<TileLogarithmBase2Attributes>::cast().listName();
    orderList << Magic<TilePowerOfTwoAttributes>::cast().listName();
    orderList << Magic<NumberDisplayAttributes>::cast().listName();

    toolbarRegistry->registerToolbar(PluginName(),orderList);
}
