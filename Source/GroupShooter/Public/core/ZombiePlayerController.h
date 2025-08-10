// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ZombiePlayerController.generated.h"

class UInputMappingContext;


/**
 * 
 */
UCLASS()
class GROUPSHOOTER_API AZombiePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AZombiePlayerController();


protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="Input", meta = (AllowPrivateAccess = "true"))
	TArray<UInputMappingContext*> DefaultMappingContexts;

	virtual void SetupInputComponent() override;


};
