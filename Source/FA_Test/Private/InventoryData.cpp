// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryData.h"

UInventoryData::UInventoryData()
{
	for (int i = 0; i < inventorySize; i++)
	{
		inventoryItems.Add(FInventorySlot(NULL, i));
	}
}

void UInventoryData::Initialize(int32 Size)
{
	inventorySize = Size;

	for (int i = 0; i < inventorySize; i++)
	{
		inventoryItems.Add(FInventorySlot(NULL, i));
	}
}

bool UInventoryData::AddItem(UItemData* ItemData)
{
	int itemSlot = GetFirstEmptySlot();

	if (itemSlot == -1)
	{
		return false;
	}

	inventoryItems[itemSlot].Item = ItemData;
	OnInventoryChanged.Broadcast();
	return true;
}

int UInventoryData::FindItemIndex(UItemData* ItemData)
{
	for (int i = 0; i < inventoryItems.Num(); i++)
	{
		if (inventoryItems[i].Item == ItemData)
		{
			return i;
		}
	}

	return -1;
}

bool UInventoryData::SwapIndexContents(int32 IndexStart, int32 IndexEnd)
{
	if (IndexStart < 0 || inventoryItems.Num() <= IndexStart
		|| IndexEnd < 0 || inventoryItems.Num() <= IndexEnd)
	{
		return false;
	}

	UItemData* startItem = inventoryItems[IndexStart].Item;
	UItemData* endItem = inventoryItems[IndexEnd].Item;

	inventoryItems[IndexStart].Item = endItem;
	inventoryItems[IndexEnd].Item = startItem;

	OnInventoryChanged.Broadcast();
	return true;
}

int UInventoryData::GetFirstEmptySlot()
{
	for (int i = 0; i < inventorySize; i++)
	{
		if (inventoryItems[i].Item == NULL)
		{
			return i;
		}
	}

	return -1;
}

bool UInventoryData::RemoveItemAt(int SlotIndex)
{
	if (SlotIndex < 0 || inventorySize <= SlotIndex)
	{
		return false;
	}

	inventoryItems[SlotIndex].Item = NULL;
	OnInventoryChanged.Broadcast();
	return true;
}
