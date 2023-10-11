#ifndef ONETOONEIDEATEMPLATE_H
#define ONETOONEIDEATEMPLATE_H

#include "../../MalamuteCore/InheritedClasses/Idea.h"
#include "../NumberDataType.h"

class OneToOneIdeaTemplate : public Idea
{
    Q_OBJECT

public:
    OneToOneIdeaTemplate();

    void onNewDataIn(std::shared_ptr<DataType> dataType, PlugNumber plugNumber) override;
    std::shared_ptr<DataType> dataOut(PlugNumber plugNumber) override;

    void updateOnOutPortLabelColor() override;
    void updateOnInPortLabelColor() override;

signals:
    void display(double input, double output);
    void clear();

protected:
    std::weak_ptr<NumberDataType> m_input;
    std::shared_ptr<NumberDataType> m_result;

    virtual void validate() = 0;
    void setupDisplay();
};

#endif // ONETOONEIDEATEMPLATE_H
