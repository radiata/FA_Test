// Copyright Epic Games, Inc. All Rights Reserved.

#include "FA_TestGameMode.h"
#include "FA_TestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFA_TestGameMode::AFA_TestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
