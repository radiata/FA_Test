// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemData.h"
#include "InventorySlot.generated.h"

USTRUCT(BlueprintType)
struct FInventorySlot
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	UItemData* Item;

	UPROPERTY(BlueprintReadOnly)
	int32 SlotID;

public:
	FInventorySlot() : Item(nullptr), SlotID(0) {};
	FInventorySlot(UItemData* ItemData, int32 ID);
};
