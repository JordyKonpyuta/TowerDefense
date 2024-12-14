// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Ennemy.generated.h"

UENUM(BlueprintType)
enum class EEnnemyType : uint8
{
	Wolf UMETA(DisplayName = "Wolf"),
	Bear UMETA(DisplayName = "Bear"),
	Bat UMETA(DisplayName = "Bat"),
	Chicken UMETA(DisplayName = "Chicken"),
};

UCLASS()
class TOWERDEFENSE_API AEnnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* SkeletalMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void OnDeath();

	UFUNCTION()
	void InitEnnemy();

};
