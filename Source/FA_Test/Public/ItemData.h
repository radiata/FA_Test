// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RenderType.h"
#include "ItemData.generated.h"

UCLASS(Blueprintable)
class FA_TEST_API UItemData : public UPrimaryDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	FText Name;
	UPROPERTY(EditAnywhere)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* texture;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMesh* model;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ERenderType renderType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* inventoryIcon;

public:
	ERenderType GetRenderType();
	UTexture2D* GetTexture();
	UStaticMesh* GetMesh();
};
