// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnnemySpawner.generated.h"

class UArrowComponent;

UCLASS()
class TOWERDEFENSE_API AEnnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnnemySpawner();

	UArrowComponent* Arrow;
	FTimerHandle SpawnTimer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SpawnEnnemy();

};
