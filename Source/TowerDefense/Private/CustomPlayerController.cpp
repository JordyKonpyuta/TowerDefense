// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"

#include "Tower.h"
#include "Tower_Child_Ghoul.h"
#include "Tower_Child_Goblin.h"
#include "Tower_Child_Lich.h"
#include "Tower_Child_Skeleton.h"
#include "Tower_Child_Zombie.h"

void ACustomPlayerController::DisplayTowerWidget_Implementation()
{
}

void ACustomPlayerController::SetPlaceTowerMode(ETowerType TowerToPlace)
{
	bIsInPlaceTowerMode = true;
	TowerType = TowerToPlace;
}
