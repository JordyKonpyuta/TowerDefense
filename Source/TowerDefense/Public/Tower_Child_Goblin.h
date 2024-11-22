// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tower.h"
#include "Tower_Child_Goblin.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API ATower_Child_Goblin : public ATower
{
	GENERATED_BODY()
	
public :
	virtual void AttackEnnemy() override;
	
	virtual void InitTower() override;
};
