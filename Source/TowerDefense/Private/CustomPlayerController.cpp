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

void ACustomPlayerController::SetSelectedTower(ETowerType TowerType)
{
	switch (TowerType)
	{
		case ETowerType::Lich:
			SelectedTower = NewObject<ATower_Child_Lich>();
			SelectedTower->InitTower();
			break;
		case ETowerType::Skeleton:
			SelectedTower = NewObject<ATower_Child_Skeleton>();
			SelectedTower->InitTower();
			break;
		case ETowerType::Ghoul:
			SelectedTower = NewObject<ATower_Child_Ghoul>();
			SelectedTower->InitTower();
			break;
		case ETowerType::Goblin:
			SelectedTower = NewObject<ATower_Child_Goblin>();
			SelectedTower->InitTower();
			break;
		case ETowerType::Zombie:
			SelectedTower = NewObject<ATower_Child_Zombie>();
			SelectedTower->InitTower();
			break;
	}
}
