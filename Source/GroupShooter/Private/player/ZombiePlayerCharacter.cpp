// Fill out your copyright notice in the Description page of Project Settings.


#include "player/ZombiePlayerCharacter.h"
#include "Components/PrimitiveComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "InputActionValue.h"
#include "InputModifiers.h"
#include "EnhancedInputComponent.h"
#include "EnhancedPlayerInput.h"
#include "InputTriggers.h"
#include "Logging/LogMacros.h"
#include "Math/MathFwd.h"


// Sets default values
AZombiePlayerCharacter::AZombiePlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	FirstPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(FName(TEXT("FPMesh")));
	FirstPersonMesh->SetupAttachment(GetMesh());
	FirstPersonMesh->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::FirstPerson;
	FirstPersonMesh->SetCollisionProfileName(FName("NoCollision"));


	
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(FName(TEXT("FPCamera")));
	FirstPersonCamera->SetupAttachment(GetMesh(), FName("FPCameraSocket"));
	FirstPersonCamera->bUsePawnControlRotation = true;
	FirstPersonCamera->bEnableFirstPersonFieldOfView = true;
	FirstPersonCamera->bEnableFirstPersonScale = true;
	FirstPersonCamera->FirstPersonFieldOfView = 70.0f;
	FirstPersonCamera->FirstPersonScale = 0.6f;

	

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

	if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(JumpAction, ETriggerEvent::Started, this, &AZombiePlayerCharacter::OnJumpedTriggered);
		Input->BindAction(JumpAction, ETriggerEvent::Completed, this, &AZombiePlayerCharacter::OnJumpedTriggeredEnd);
	
		Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AZombiePlayerCharacter::Moving);
		

	}
}

void AZombiePlayerCharacter::OnJumpedTriggered(const FInputActionInstance& Instance)
{
	UE_LOG(LogTemp, Warning, TEXT("Jumping"));
	Jump();
}

void AZombiePlayerCharacter::OnJumpedTriggeredEnd(const FInputActionInstance& Instance)
{
	UE_LOG(LogTemp, Warning, TEXT("Finished Jumping"));
	StopJumping();
}

void AZombiePlayerCharacter::Moving(const FInputActionValue& Value)
{
	FVector2D tmp = Value.Get<FVector2D>();
	UE_LOG(LogTemp, Warning, TEXT("Moving: %f, %f"), tmp.X, tmp.Y);
}

