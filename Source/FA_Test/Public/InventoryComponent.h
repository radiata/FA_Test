// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryData.h"
#include "InventoryComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FA_TEST_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int32 InventorySize;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInventoryData* inventory;

public:	
	UInventoryComponent();
	bool AddToInventory(UItemData* ItemData);

	UFUNCTION(BlueprintCallable)
	bool RemoveFromInventory(UItemData* ItemData);

protected:
	virtual void BeginPlay() override;
};
