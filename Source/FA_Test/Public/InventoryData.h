// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventorySlot.h"
#include "InventoryData.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryChangedEvent);


UCLASS(BlueprintType)
class FA_TEST_API UInventoryData : public UObject
{
	GENERATED_BODY()

protected:
	int inventorySize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<FInventorySlot> inventoryItems;

public:
	UInventoryData();
	void Initialize(int32 Size);
	bool AddItem(UItemData* ItemData);
	int FindItemIndex(UItemData* ItemData);
	bool RemoveItemAt(int SlotIndex);

	UFUNCTION(BlueprintCallable)
	bool SwapIndexContents(int32 IndexStart, int32 IndexEnd);

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnInventoryChangedEvent OnInventoryChanged;

private:
	int GetFirstEmptySlot();
};
