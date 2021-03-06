#pragma once

#include "AdaptiveCards.XamlCardRenderer.h"
#include "Enums.h"
#include "HostOptions.h"

namespace AdaptiveCards { namespace XamlCardRenderer
{
    class AdaptiveContainerOptions :
        public Microsoft::WRL::RuntimeClass<
            Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
            ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveContainerOptions>
    {
        InspectableClass(RuntimeClass_AdaptiveCards_XamlCardRenderer_AdaptiveContainerOptions, BaseTrust)

    public:
        HRESULT RuntimeClassInitialize() noexcept;
        HRESULT RuntimeClassInitialize(ContainerOptions containerOptions) noexcept;

        IFACEMETHODIMP get_Separation(_Out_ ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveSeparationOptions** separationOptions);
        IFACEMETHODIMP put_Separation(_In_ ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveSeparationOptions* separationOptions);

        IFACEMETHODIMP get_Normal(_Out_ ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveContainerStyleConfig** containerStyleconfig);
        IFACEMETHODIMP put_Normal(_In_ ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveContainerStyleConfig* containerStyleconfig);

        IFACEMETHODIMP get_Emphasis(_Out_ ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveContainerStyleConfig** containerStyleconfig);
        IFACEMETHODIMP put_Emphasis(_In_ ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveContainerStyleConfig* containerStyleconfig);

    private:
        ContainerOptions m_sharedContainerOptions;
    };

    ActivatableClass(AdaptiveContainerOptions);
}}