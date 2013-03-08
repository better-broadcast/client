#pragma once

#include "../Shared.h"

#include <QtCore/QObject>
#include <QtCore/QString>

class CORE_EXPORT LibraryModel
{
    public:
        explicit LibraryModel() { }
        explicit LibraryModel(int id, const QString& label, const QString& name, const QString& deviceName, const QString& type, int thumbnailId);

        int getId() const;
        const QString& getLabel() const;
        const QString& getName() const;
        const QString& getDeviceName() const;
        const QString& getType() const;
        int getThumbnailId() const;

        void setLabel(const QString& label);
        void setName(const QString& name);
        void setDeviceName(const QString& deviceName);

    private:
        int id;
        QString label;
        QString name;
        QString deviceName;
        QString type;
        int thumbnailId;
};
