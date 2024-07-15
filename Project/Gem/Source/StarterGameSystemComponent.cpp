
#include <AzCore/Serialization/SerializeContext.h>

#include "StarterGameSystemComponent.h"

#include <StarterGame/StarterGameTypeIds.h>

namespace StarterGame
{
    AZ_COMPONENT_IMPL(StarterGameSystemComponent, "StarterGameSystemComponent",
        StarterGameSystemComponentTypeId);

    void StarterGameSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<StarterGameSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void StarterGameSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("StarterGameService"));
    }

    void StarterGameSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("StarterGameService"));
    }

    void StarterGameSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void StarterGameSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    StarterGameSystemComponent::StarterGameSystemComponent()
    {
        if (StarterGameInterface::Get() == nullptr)
        {
            StarterGameInterface::Register(this);
        }
    }

    StarterGameSystemComponent::~StarterGameSystemComponent()
    {
        if (StarterGameInterface::Get() == this)
        {
            StarterGameInterface::Unregister(this);
        }
    }

    void StarterGameSystemComponent::Init()
    {
    }

    void StarterGameSystemComponent::Activate()
    {
        StarterGameRequestBus::Handler::BusConnect();
    }

    void StarterGameSystemComponent::Deactivate()
    {
        StarterGameRequestBus::Handler::BusDisconnect();
    }
}
