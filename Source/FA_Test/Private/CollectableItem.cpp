#include "CollectableItem.h"


ACollectableItem::ACollectableItem()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACollectableItem::OnInteract_Implementation(AActor* Interactor)
{
	UInventoryComponent* inventory = Interactor->GetComponentByClass<UInventoryComponent>();
	
	if (inventory != NULL)
	{
		bool result = inventory->AddToInventory(ItemData);
		if (result == true)
		{
			Destroy();
		}
	}
}

