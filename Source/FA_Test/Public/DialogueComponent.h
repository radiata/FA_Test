// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DialogueData.h"
#include "DialogueComponent.generated.h"


UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FA_TEST_API UDialogueComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	UDialogueData* dialogueData;

public:	
	void SetActiveDialogue(UDialogueData* data);

	UFUNCTION(BlueprintImplementableEvent)
	void StartDialogue();
		
};
