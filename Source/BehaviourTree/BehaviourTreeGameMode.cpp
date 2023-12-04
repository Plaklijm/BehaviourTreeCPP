// Copyright Epic Games, Inc. All Rights Reserved.

#include "BehaviourTreeGameMode.h"
#include "BehaviourTreeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABehaviourTreeGameMode::ABehaviourTreeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
