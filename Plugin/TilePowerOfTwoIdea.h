#ifndef TILEPOWEROFTWOIDEA_H
#define TILEPOWEROFTWOIDEA_H

#include "PowerOfTwoIdea.h"

struct TilePowerOfTwoAttributes : public IdeaAttributes
{
    TilePowerOfTwoAttributes();
};

class TilePowerOfTwoIdea : public PowerOfTwoIdea
{
    Q_OBJECT

public:
    explicit TilePowerOfTwoIdea();
    const IdeaAttributes attributes() override;

    void resetDisplay() override;
};

#endif // TILEPOWEROFTWOIDEA_H
