#include "OpacityCommand.h"

#include <QtCore/QXmlStreamWriter>

OpacityCommand::OpacityCommand(QObject* parent)
    : AbstractCommand(parent)
{
}

float OpacityCommand::getOpacity() const
{
    return this->opacity;
}

int OpacityCommand::getTransitionDuration() const
{
    return this->transitionDuration;
}

const QString& OpacityCommand::getTween() const
{
    return this->tween;
}

bool OpacityCommand::getTriggerOnNext() const
{
    return this->triggerOnNext;
}

bool OpacityCommand::getDefer() const
{
    return this->defer;
}

void OpacityCommand::setOpacity(float opacity)
{
    this->opacity = opacity;
    emit opacityChanged(this->opacity);
}

void OpacityCommand::setTransitionDuration(int transitionDuration)
{
    this->transitionDuration = transitionDuration;
    emit transitionDurationChanged(this->transitionDuration);
}

void OpacityCommand::setTween(const QString& tween)
{
    this->tween = tween;
    emit tweenChanged(this->tween);
}

void OpacityCommand::setTriggerOnNext(bool triggerOnNext)
{
    this->triggerOnNext = triggerOnNext;
    emit triggerOnNextChanged(this->triggerOnNext);
}

void OpacityCommand::setDefer(bool defer)
{
    this->defer = defer;
    emit deferChanged(this->defer);
}

void OpacityCommand::readProperties(boost::property_tree::wptree& pt)
{
    AbstractCommand::readProperties(pt);

    setOpacity(pt.get(L"opacity", Mixer::DEFAULT_OPACITY));
    setTransitionDuration(pt.get(L"transitionDuration", pt.get(L"transtitionDuration", Mixer::DEFAULT_DURATION)));
    setTween(QString::fromStdWString(pt.get(L"tween", Mixer::DEFAULT_TWEEN.toStdWString())));
    setTriggerOnNext(pt.get(L"triggeronnext", Opacity::DEFAULT_TRIGGER_ON_NEXT));
    setDefer(pt.get(L"defer", Mixer::DEFAULT_DEFER));
}

void OpacityCommand::writeProperties(QXmlStreamWriter& writer)
{
    AbstractCommand::writeProperties(writer);

    writer.writeTextElement("opacity", QString::number(getOpacity()));
    writer.writeTextElement("transitionDuration", QString::number(getTransitionDuration()));
    writer.writeTextElement("tween", getTween());
    writer.writeTextElement("triggeronnext", (getTriggerOnNext() == true) ? "true" : "false");
    writer.writeTextElement("defer", (getDefer() == true) ? "true" : "false");
}
