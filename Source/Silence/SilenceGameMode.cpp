// Copyright Epic Games, Inc. All Rights Reserved.

#include "SilenceGameMode.h"
#include "SilenceCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASilenceGameMode::ASilenceGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Assets/Blueprints/Player/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
