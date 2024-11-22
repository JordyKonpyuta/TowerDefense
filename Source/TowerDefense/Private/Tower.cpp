// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "CustomPlayerController.h"

// Sets default values
ATower::ATower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Pillar = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pillar"));
	TowerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TowerMesh"));
	SetRootComponent(Pillar);
	TowerMesh->SetVisibility(false);

}

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<ACustomPlayerController>(GetWorld()->GetFirstPlayerController());
	
}

// Called every frame
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATower::AttackEnnemy()
{
}

void ATower::SetTowerMesh()
{
	if (bIsAvailable)
	{
		TowerMesh->SetVisibility(true);
		TowerMesh = PlayerController->SelectedTower->TowerMesh;
		for (int i = 0; i < TowerMesh->GetNumMaterials(); i++)
		{
			TowerMesh->SetMaterial(i, (ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Script/Engine.Material'/Game/Assets/M_PreviewTower.M_PreviewTower'")).Object));
		}
	}
}

void ATower::OnUnhovered()
{
	TowerMesh->SetVisibility(false);
}

void ATower::OnClicked()
{
	if (bIsAvailable)
	{
		TowerMesh = PlayerController->SelectedTower->TowerMesh;
		Attack = PlayerController->SelectedTower->Attack;
		AttackSpeed = PlayerController->SelectedTower->AttackSpeed;
		Price = PlayerController->SelectedTower->Price;
		PlayerController->Gold = PlayerController->Gold - PlayerController->SelectedTower->Price;
		PlayerController->SelectedTower = nullptr;
		bIsAvailable = false;
	}

	else
	{
		PlayerController->DisplayTowerWidget();
	}

}

void ATower::InitTower()
{
}

