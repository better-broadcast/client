#pragma once

#include "../../Shared.h"
#include "../AbstractCommand.h"

#include "Global.h"

#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <QtCore/QObject>
#include <QtCore/QString>

class QXmlStreamWriter;

class CORE_EXPORT AtemMacroCommand : public AbstractCommand
{
    Q_OBJECT

    public:
        explicit AtemMacroCommand(QObject* parent = 0);

        virtual void readProperties(boost::property_tree::wptree& pt);
        virtual void writeProperties(QXmlStreamWriter& writer);

        const QString& getMacro() const;
        bool getTriggerOnNext() const;

        void setMacro(const QString& macro);
        void setTriggerOnNext(bool triggerOnNext);

    private:
        QString macro = Atem::DEFAULT_MACRO;
        bool triggerOnNext = Atem::DEFAULT_TRIGGER_ON_NEXT;

        Q_SIGNAL void macroChanged(const QString&);
        Q_SIGNAL void triggerOnNextChanged(bool);
};
