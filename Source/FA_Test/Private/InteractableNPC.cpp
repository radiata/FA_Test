#include "InteractableNPC.h"

AInteractableNPC::AInteractableNPC()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AInteractableNPC::OnInteract_Implementation(AActor* Interactor)
{
	UDialogueComponent* dialogue = Interactor->GetComponentByClass<UDialogueComponent>();
	dialogue->SetActiveDialogue(dialogueData);
	dialogue->StartDialogue();
}


