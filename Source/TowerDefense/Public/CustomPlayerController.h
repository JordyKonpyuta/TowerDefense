// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CustomPlayerController.generated.h"

/**
 * 
 */

class ATower;

UENUM(BlueprintType)
enum class ETowerType : uint8
{
	Lich UMETA(DisplayName = "Lich"),
	Skeleton UMETA(DisplayName = "Skeleton"),
	Ghoul UMETA(DisplayName = "Ghoul"),
	Goblin UMETA(DisplayName = "Goblin"),
	Zombie UMETA(DisplayName = "Zombie"),
};

UCLASS()
class TOWERDEFENSE_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	int Gold = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	int Health = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	int Wave = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	int Score = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	ATower* SelectedTower;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void DisplayTowerWidget();

	UFUNCTION(BlueprintCallable)
	void SetSelectedTower(ETowerType TowerType);
};
