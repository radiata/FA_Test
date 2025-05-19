#pragma once

#include "CoreMinimal.h"
#include "DialogueLine.generated.h"

USTRUCT(BlueprintType)
struct FA_TEST_API FDialogueLine
{
	GENERATED_BODY() 

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Speaker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Line;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FText> Responses;
};
