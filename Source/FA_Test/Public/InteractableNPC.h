// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "DialogueComponent.h"
#include "DialogueData.h"
#include "InteractableNPC.generated.h"

UCLASS()
class FA_TEST_API AInteractableNPC : public AActor, public IInteractable
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	UDialogueData* dialogueData;
	
public:	
	AInteractableNPC();


public:
	virtual void OnInteract_Implementation(AActor* Interactor) override;

};
