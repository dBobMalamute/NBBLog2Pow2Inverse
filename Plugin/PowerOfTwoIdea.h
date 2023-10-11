#ifndef POWEROFTWOIDEA_H
#define POWEROFTWOIDEA_H

#include "IdeaTemplates/OneToOneIdeaTemplate.h"

struct PowerOfTwoAttributes : public IdeaAttributes
{
    PowerOfTwoAttributes();
};

class PowerOfTwoIdea : public OneToOneIdeaTemplate
{
    Q_OBJECT

public:
    explicit PowerOfTwoIdea();
    const IdeaAttributes attributes() override;

private:
    void validate() override;
    void compute(double n1);
};

#endif // POWEROFTWOIDEA_H
