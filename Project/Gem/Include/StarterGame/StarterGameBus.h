
#pragma once

#include <StarterGame/StarterGameTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace StarterGame
{
    class StarterGameRequests
    {
    public:
        AZ_RTTI(StarterGameRequests, StarterGameRequestsTypeId);
        virtual ~StarterGameRequests() = default;
        // Put your public methods here
    };

    class StarterGameBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using StarterGameRequestBus = AZ::EBus<StarterGameRequests, StarterGameBusTraits>;
    using StarterGameInterface = AZ::Interface<StarterGameRequests>;

} // namespace StarterGame
