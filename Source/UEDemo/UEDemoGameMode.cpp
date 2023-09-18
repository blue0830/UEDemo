// Copyright Epic Games, Inc. All Rights Reserved.

#include "UEDemoGameMode.h"
#include "UEDemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUEDemoGameMode::AUEDemoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
