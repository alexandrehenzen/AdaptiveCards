#pragma once

#include "AdaptiveCards.XamlCardRenderer.h"
#include "Enums.h"
#include "InputChoiceSet.h"
#include <windows.foundation.h>

namespace AdaptiveCards { namespace XamlCardRenderer
{
    class AdaptiveInputChoiceSet :
        public Microsoft::WRL::RuntimeClass<
            Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
            ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveInputChoiceSet,
            ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveInputElement,
            ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveCardElement>
    {
        InspectableClass(RuntimeClass_AdaptiveCards_XamlCardRenderer_AdaptiveInputChoiceSet, BaseTrust)

    public:
        AdaptiveInputChoiceSet();

        HRESULT RuntimeClassInitialize() noexcept;
        HRESULT RuntimeClassInitialize(_In_ const std::shared_ptr<AdaptiveCards::InputChoiceSet>& sharedInputChoiceSet);

        // IAdaptiveInputChoiceSet

        IFACEMETHODIMP get_IsMultiSelect(_Out_ boolean* isMultiSelect);
        IFACEMETHODIMP put_IsMultiSelect(_In_ boolean isMultiSelect);

        IFACEMETHODIMP get_IsRequired(_Out_ boolean* isRequired);
        IFACEMETHODIMP put_IsRequired(_In_ boolean isRequired);

        IFACEMETHODIMP get_ChoiceSetStyle(_Out_ ABI::AdaptiveCards::XamlCardRenderer::ChoiceSetStyle* choiceSetStyle);
        IFACEMETHODIMP put_ChoiceSetStyle(_In_ ABI::AdaptiveCards::XamlCardRenderer::ChoiceSetStyle choiceSetStyle);

        IFACEMETHODIMP get_Choices(_COM_Outptr_ ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveInputChoice*>** columns);

        // IAdaptiveInputElement
        IFACEMETHODIMP get_Id(_Out_ HSTRING* text);
        IFACEMETHODIMP put_Id(_In_ HSTRING text);

        // IAdaptiveCardElement
        IFACEMETHODIMP get_ElementType(_Out_ ABI::AdaptiveCards::XamlCardRenderer::ElementType* elementType);

        IFACEMETHODIMP get_Separation(_Out_ ABI::AdaptiveCards::XamlCardRenderer::SeparationStyle* separation);
        IFACEMETHODIMP put_Separation(_In_ ABI::AdaptiveCards::XamlCardRenderer::SeparationStyle separation);

        IFACEMETHODIMP get_Speak(_In_ HSTRING* speak);
        IFACEMETHODIMP put_Speak(_Out_ HSTRING speak);

    private:
        // TODO: MSFT 11015796: Sync UWP Projection container classes to Shared object model counterparts.
        Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveInputChoice*>> m_InputChoices;

        //Using a Container as backing element for now
        std::shared_ptr<AdaptiveCards::InputChoiceSet> m_sharedInputChoiceSet;
    };

    ActivatableClass(AdaptiveInputChoiceSet);
}}
