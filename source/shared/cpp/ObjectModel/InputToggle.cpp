#include "InputToggle.h"
#include "ParseUtil.h"

using namespace AdaptiveCards;

InputToggle::InputToggle() :
    BaseInputElement(CardElementType::InputToggle),
    m_valueOn("true"),
    m_valueOff("false")
{
}

std::shared_ptr<InputToggle> InputToggle::Deserialize(const Json::Value& json)
{
    ParseUtil::ExpectTypeString(json, CardElementType::InputToggle);

    std::shared_ptr<InputToggle> inputToggle = BaseInputElement::Deserialize<InputToggle>(json);

    inputToggle->SetTitle(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Title, true));
    inputToggle->SetValue(ParseUtil::GetString(json, AdaptiveCardSchemaKey::Value));

    std::string valueOff = ParseUtil::GetString(json, AdaptiveCardSchemaKey::ValueOff);
    if (valueOff != "")
    {
        inputToggle->SetValueOff(valueOff);
    }

    std::string valueOn = ParseUtil::GetString(json, AdaptiveCardSchemaKey::ValueOn);
    if (valueOn != "")
    {
        inputToggle->SetValueOn(valueOn);
    }

    return inputToggle;
}

std::shared_ptr<InputToggle> InputToggle::DeserializeFromString(const std::string& jsonString)
{
    return InputToggle::Deserialize(ParseUtil::GetJsonValueFromString(jsonString));
}

std::string InputToggle::Serialize()
{
    return "";
}

std::string InputToggle::GetTitle() const
{
    return m_title;
}

void InputToggle::SetTitle(const std::string value)
{
    m_title = value;
}

std::string InputToggle::GetValue() const
{
    return m_value;
}

void InputToggle::SetValue(const std::string value)
{
    m_value = value;
}
void InputToggle::SetValueOff(const std::string valueOff)
{
    m_valueOff = valueOff;
}

std::string InputToggle::GetValueOff() const
{
    return m_valueOff;
}

std::string InputToggle::GetValueOn() const
{
    return m_valueOn;
}

void InputToggle::SetValueOn(const std::string valueOn)
{
    m_valueOn = valueOn;
}