// Fill out your copyright notice in the Description page of Project Settings.

#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "core/ZombiePlayerController.h"



AZombiePlayerController::AZombiePlayerController()
{

}

void AZombiePlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}