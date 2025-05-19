#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DialogueLine.h"
#include "DialogueData.generated.h"


UCLASS(Blueprintable)
class FA_TEST_API UDialogueData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText dialogueID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FDialogueLine> dialogueLines;
};
