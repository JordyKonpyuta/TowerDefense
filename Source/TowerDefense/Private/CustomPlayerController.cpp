// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"

#include "Tower.h"

void ACustomPlayerController::DisplayTowerWidget_Implementation()
{
}

void ACustomPlayerController::SetSelectedTower(ETowerType TowerType)
{
	switch (TowerType)
	{
		case ETowerType::Lich:
			SelectedTower = NewObject<ATower>();
			SelectedTower->InitTower(ETowerName::Lich);
			break;
		case ETowerType::Skeleton:
			SelectedTower = NewObject<ATower>();
			SelectedTower->InitTower(ETowerName::Skeleton);
			break;
		case ETowerType::Ghoul:
			SelectedTower = NewObject<ATower>();
			SelectedTower->InitTower(ETowerName::Ghoul);
			break;
		case ETowerType::Goblin:
			SelectedTower = NewObject<ATower>();
			SelectedTower->InitTower(ETowerName::Goblin);
			break;
		case ETowerType::Zombie:
			SelectedTower = NewObject<ATower>();
			SelectedTower->InitTower(ETowerName::Zombie);
			break;
	}
}
