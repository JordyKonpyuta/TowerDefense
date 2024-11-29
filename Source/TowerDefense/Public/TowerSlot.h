// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TowerSlot.generated.h"

class ACustomPlayerController;
class UArrowComponent;
class ATower;

UCLASS()
class TOWERDEFENSE_API ATowerSlot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATowerSlot();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	USkeletalMeshComponent* TowerMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	bool bIsAvailable = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	ACustomPlayerController* PlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UArrowComponent* Arrow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ATower* TowerRef = nullptr;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
	UStaticMeshComponent* Pillar;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetTowerMesh();

	UFUNCTION(BlueprintNativeEvent)
	void SelectTowerType();

	UFUNCTION(BlueprintCallable)
	void OnUnhovered();

	UFUNCTION(BlueprintCallable)
	void OnClicked();

};
