#ifndef IDEAREGISTRY_H
#define IDEAREGISTRY_H

#include <unordered_map>
#include "../InheritedClasses/Idea.h"

/// Class uses map for storing ideas (name, idea)
class IdeaRegistry
{
public:

    template<typename IdeaType> void registerIdea()
    {
        auto idea = std::make_unique<IdeaType>();

        std::function<std::unique_ptr<Idea>()> constructorDispatchFunc = []()
        {
            return std::make_unique<IdeaType>();
        };

        QString listName = idea->attributes().listName();
        QString iconPath = idea->attributes().iconPath();

        if (m_dispatchTable.count(listName) == 0)
        {
            m_dispatchTable[listName] = std::move(constructorDispatchFunc);
            m_iconPaths[listName] = iconPath;
        }
    }

    std::unique_ptr<Idea> createIdea (QString const &listName);
    QString iconPath(QString listName);
    QStringList registeredIdeaNames();

private:
    std::unordered_map<QString, std::function<std::unique_ptr<Idea>()>> m_dispatchTable;
    std::unordered_map<QString, QString> m_iconPaths;
};

#endif // IDEAREGISTRY_H
