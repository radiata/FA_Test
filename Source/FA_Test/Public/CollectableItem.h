// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "ItemData.h"
#include "InventoryComponent.h"
#include "CollectableItem.generated.h"

UCLASS(Blueprintable)
class FA_TEST_API ACollectableItem : public AActor, public IInteractable
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	UItemData* ItemData;
	
public:	
	ACollectableItem();


public:	
	virtual void OnInteract_Implementation(AActor* Interactor) override;
};
