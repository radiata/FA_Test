// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySlot.h"

FInventorySlot::FInventorySlot(UItemData* ItemData, int32 ID)
{
	Item = ItemData;
	SlotID = ID;
}
