#ifndef CHANGECOLORSCOMMAND_H
#define CHANGECOLORSCOMMAND_H

#include "UndoCommand.h"
#include <QJsonObject>

class Corkboard;
class ChangeColorsCommand : public UndoCommand
{
public:
    ChangeColorsCommand(std::vector<QUuid> ids, const std::vector<int> oldColors, const int newColor, Corkboard* corkboard);

    void undo() override;
    void redo() override;

private:
    std::vector<QUuid> m_ids;

    std::vector<int> m_oldColors;
    int m_newColor;

    Corkboard* m_corkboard;
};

#endif // CHANGECOLORCOMMAND_H
