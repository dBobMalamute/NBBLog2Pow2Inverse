#ifndef WIREBACKEND_H
#define WIREBACKEND_H

#include <memory>

#include <QObject>
#include <QUuid>
#include <QVariant>

#include "Plug.h"
#include "InheritedClasses/DataType.h"
#include "WireState.h"
#include "CasingBackend.h"
#include "InheritedClasses/Idea.h"
#include "Wire.h"

class WireBackend: public QObject
{
    Q_OBJECT

public:
    WireBackend(PlugType plugType, CasingBackend* casingBackend, PlugNumber plugNumber);
    WireBackend(QUuid id, CasingBackend *inCasingBackend, PlugNumber inPlugNumber,
                CasingBackend *outCasingBackend, PlugNumber outPlugNumber);

    WireBackend(const WireBackend&) = delete;
    WireBackend operator=(const WireBackend&) = delete;

    ~WireBackend() override;

public:
    QJsonObject serialize() const;

public:

    QUuid id() const;

    void setRequiredPlugType(PlugType plugType);
    PlugType requiredPlugType() const;

    void setWire(Wire* wire);

    /// Assigns a casing to the required plug.
    /// It is assumed that there is a required plug, no extra checks
    void setCasingToPlug(CasingBackend *casingBackend, PlugType plugType, PlugNumber plugNumber);

    void removeFromCasings() const;

public:

    Wire *getWire() const;

    WireState const & state() const;
    WireState& state();

    CasingBackend* getCasing(PlugType plugType) const;
    CasingBackend*& getCasing(PlugType plugType);

    PlugNumber getPlugIndex(PlugType plugType) const;

    void clearCasingBackend(PlugType plugType);

    int dataType(PlugType plugType) const;
    int dataType() const;

    bool complete() const;

    void propagateData(std::shared_ptr<DataType> dataType) const;
    void propagateEmptyData() const;

signals:
    void wireBackendCompleted(WireBackend const&) const;
    void wireBackendMadeIncomplete(WireBackend const&) const;
    void updated(WireBackend& conn) const;

private:
    QUuid m_uid;

private:
    CasingBackend* m_outCasingBackend = nullptr;
    CasingBackend* m_inCasingBackend  = nullptr;

    PlugNumber m_outPlugNumber;
    PlugNumber m_inPlugNumber;

private:
    WireState m_state;
    Wire* m_wire;
};

#endif //WIREBACKEND_H
