// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UInventoryComponent::AddToInventory(UItemData* ItemData)
{
	return inventory->AddItem(ItemData);
}

bool UInventoryComponent::RemoveFromInventory(UItemData* ItemData)
{
	int index =  inventory->FindItemIndex(ItemData);

	if (index < 0)
	{
		return false;
	}

	return inventory->RemoveItemAt(index);
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	inventory = NewObject< UInventoryData>(this);
	inventory->Initialize(InventorySize);
}



