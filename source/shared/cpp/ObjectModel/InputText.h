#pragma once

#include "pch.h"
#include "BaseInputElement.h"
#include "Enums.h"

namespace AdaptiveCards
{
class InputText : public BaseInputElement
{
public:
    InputText();

    static std::shared_ptr<InputText> Deserialize(const Json::Value& root);
    static std::shared_ptr<InputText> DeserializeFromString(const std::string& jsonString);

    virtual std::string Serialize();

    std::string GetPlaceholder() const;
    void SetPlaceholder(const std::string value);

    std::string GetValue() const;
    void SetValue(const std::string value);

    bool GetIsMultiline() const;
    void SetIsMultiline(const bool value);

    unsigned int GetMaxLength() const;
    void SetMaxLength(const unsigned int value);

    TextInputStyle GetTextInputStyle() const;
    void SetTextInputStyle(const TextInputStyle value);

private:
    std::string m_placeholder;
    std::string m_value;
    bool m_isMultiline;
    unsigned int m_maxLength;
    TextInputStyle m_style;
};
}