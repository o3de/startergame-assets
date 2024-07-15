
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "StarterGameSystemComponent.h"

#include <StarterGame/StarterGameTypeIds.h>

namespace StarterGame
{
    class StarterGameModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(StarterGameModule, StarterGameModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(StarterGameModule, AZ::SystemAllocator);

        StarterGameModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                StarterGameSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<StarterGameSystemComponent>(),
            };
        }
    };
}// namespace StarterGame

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), StarterGame::StarterGameModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_StarterGame, StarterGame::StarterGameModule)
#endif
