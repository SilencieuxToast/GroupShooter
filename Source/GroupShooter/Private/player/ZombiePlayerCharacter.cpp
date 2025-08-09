// Fill out your copyright notice in the Description page of Project Settings.


#include "player/ZombiePlayerCharacter.h"

// Sets default values
AZombiePlayerCharacter::AZombiePlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AZombiePlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZombiePlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AZombiePlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

