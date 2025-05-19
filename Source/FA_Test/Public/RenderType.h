// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RenderType.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ERenderType : uint8
{
	TwoDimensional UMETA(DisplayName = "2D"),
	ThreeDimensional UMETA(DisplayName = "3D")
};
