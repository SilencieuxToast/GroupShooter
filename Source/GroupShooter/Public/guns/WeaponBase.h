// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Handgun UMETA(DisplayName="Pistols"),
	Shotgun UMETA(DisplayName="Shotguns"),
	Sniper UMETA(DisplayName="Snipers"),
	Rifles UMETA(DisplayName="Rifles")

};

USTRUCT(BlueprintType)
struct FWeaponStats
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	float ReloadSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	float FireRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	float BulletVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	int32 AmmoCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Stats")
	int32 CurrentClip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	int32 MagSize;
};

UCLASS()
class GROUPSHOOTER_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
