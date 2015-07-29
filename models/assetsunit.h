#ifndef ASSETSUNIT_H
#define ASSETSUNIT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AssetsUnitObject;
class QJsonArray;


class T_MODEL_EXPORT AssetsUnit : public TAbstractModel
{
public:
    AssetsUnit();
    AssetsUnit(const AssetsUnit &other);
    AssetsUnit(const AssetsUnitObject &object);
    ~AssetsUnit();

    int assetsUnitID() const;
    void setAssetsUnitID(int assetsUnitID);
    int managerID() const;
    void setManagerID(int managerID);
    QString assetsUnitShortname() const;
    void setAssetsUnitShortname(const QString &assetsUnitShortname);
    AssetsUnit &operator=(const AssetsUnit &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static AssetsUnit create(int assetsUnitID, int managerID, const QString &assetsUnitShortname);
    static AssetsUnit create(const QVariantMap &values);
    static AssetsUnit get(int assetsUnitID);
    static int count();
    static QList<AssetsUnit> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<AssetsUnitObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(AssetsUnit)
Q_DECLARE_METATYPE(QList<AssetsUnit>)

#endif // ASSETSUNIT_H
