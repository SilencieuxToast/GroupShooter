// Fill out your copyright notice in the Description page of Project Settings.


#include "player/ZombiePlayerCharacter.h"
#include "Components/PrimitiveComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
//#include "GameFramework/SpringArmComponent.h"
#include "Components/SkinnedMeshComponent.h"
#include "Containers/Array.h"
#include "Engine/SkeletalMesh.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputActionValue.h"
#include "InputModifiers.h"
#include "EnhancedInputComponent.h"
#include "EnhancedPlayerInput.h"
#include "InputTriggers.h"
#include "Logging/LogMacros.h"
#include "Logging/LogVerbosity.h"
#include "Math/MathFwd.h"
#include "GameFramework/CharacterMovementComponent.h"

class USpringArmComponent;

// Sets default values
AZombiePlayerCharacter::AZombiePlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCharacterMovement()->MaxCustomMovementSpeed = GetCharacterMovement()->MaxWalkSpeed;
	SprintSpeed = GetCharacterMovement()->GetMaxSpeed() * SprintSpeed;
	

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(FName("SpringArm"));
	SpringArmComp->SetupAttachment(GetMesh(), FName("CameraSocket"));
	SpringArmComp->TargetArmLength = 0;
	
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(FName(TEXT("FPCamera")));
	FirstPersonCamera->SetupAttachment(SpringArmComp);
	FirstPersonCamera->bUsePawnControlRotation = true;
	FirstPersonCamera->bEnableFirstPersonFieldOfView = true;
	FirstPersonCamera->bEnableFirstPersonScale = true;
	FirstPersonCamera->FirstPersonFieldOfView = 70.0f;
	FirstPersonCamera->FirstPersonScale = 0.6f;

	/*
	FirstPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(FName(TEXT("FPMesh")));
	FirstPersonMesh->SetupAttachment(FirstPersonCamera);
	FirstPersonMesh->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::FirstPerson;
	FirstPersonMesh->SetCollisionProfileName(FName("NoCollision"));
*/

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

		Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &AZombiePlayerCharacter::Look);

		Input->BindAction(SprintAction, ETriggerEvent::Started, this, &AZombiePlayerCharacter::SprintStart);
		Input->BindAction(SprintAction, ETriggerEvent::Completed, this, &AZombiePlayerCharacter::SprintEnd);
		

	}
}

void AZombiePlayerCharacter::OnJumpedTriggered(const FInputActionValue& Value)
{
	if (CanJump())
	{
		UE_LOG(LogTemp, Warning, TEXT("Jumping"));
		Jump();
	}
	
}

void AZombiePlayerCharacter::OnJumpedTriggeredEnd(const FInputActionValue& Value)
{
		StopJumping();
		UE_LOG(LogTemp, Warning, TEXT("Can't Jump"));
	
}

void AZombiePlayerCharacter::Moving(const FInputActionValue& Value)
{
	FVector2D tmp = Value.Get<FVector2D>();
	//UE_LOG(LogTemp, Warning, TEXT("Moving: %f, %f"), tmp.X, tmp.Y);

	if (Controller != nullptr)
	{
		//FRotator PlayerRotation = GetControlRotation();
		const FVector Right = GetActorRightVector();
		AddMovementInput(Right, tmp.X, false);

		const FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, tmp.Y, false);

	}

}

void AZombiePlayerCharacter::Look(const FInputActionValue& Value)
{

	if (Controller != nullptr)
	{
		FVector2D AimLook = Value.Get<FVector2D>();
		//UE_LOG(LogTemp, Warning, TEXT("AimLook: %f, %f"), AimLook.X, AimLook.Y);
		
		AddControllerPitchInput(-AimLook.Y);
		AddControllerYawInput(AimLook.X);
		
		
		/*
		FRotator AimRotation = GetBaseAimRotation();
		UE_LOG(LogTemp, Warning, TEXT("AimRotation: %f, %f, %f"), AimRotation.Roll, AimRotation.Pitch, AimRotation.Yaw);

		*/
	}
}

void AZombiePlayerCharacter::SprintStart(const FInputActionValue& Value)
{	
	GetCharacterMovement()->MaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed * SprintSpeed;
	
	

}

void AZombiePlayerCharacter::SprintEnd(const FInputActionValue& Value)
{

	
	GetCharacterMovement()->MaxWalkSpeed = GetCharacterMovement()->MaxCustomMovementSpeed;
	UE_LOG(LogTemp, Warning, TEXT("Sprinting Speed: %f"), GetCharacterMovement()->MaxWalkSpeed);


}