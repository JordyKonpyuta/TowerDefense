// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tower.h"
#include "Tower_Child_Ghoul.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API ATower_Child_Ghoul : public ATower
{
	GENERATED_BODY()

	virtual void AttackEnnemy() override;

	virtual void InitTower() override;
};
