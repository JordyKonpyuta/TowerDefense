// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tower.generated.h"

class ACustomPlayerController;
class ABaseProjectile;

UCLASS()
class TOWERDEFENSE_API ATower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATower();


	// COMPONENTS
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	USkeletalMeshComponent* TowerMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimSequence* IdleAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimSequence* SpawnAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TArray<UAnimSequence*> AttackAnimations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimSequence* AgrouAnimation;


	// STATS
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	int Attack = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	float AttackSpeed = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	int Price = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	ABaseProjectile* Projectile;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void AttackEnnemy();
	

	UFUNCTION(BlueprintCallable)
	virtual void InitTower();

};
