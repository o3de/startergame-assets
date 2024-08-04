
#pragma once

#include <AzCore/Component/Component.h>

#include <StarterGame/StarterGameBus.h>

namespace StarterGame
{
    class StarterGameSystemComponent
        : public AZ::Component
        , protected StarterGameRequestBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(StarterGameSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        StarterGameSystemComponent();
        ~StarterGameSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // StarterGameRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
