// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tower.h"
#include "Tower_Child_Lich.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API ATower_Child_Lich : public ATower
{
	GENERATED_BODY()

public:

	virtual void InitTower() override;

	virtual void AttackEnnemy() override;
	
};
