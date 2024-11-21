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
		CanAttack = PlayerController->SelectedTower->CanAttack;
		PlayerController->Gold = PlayerController->Gold - PlayerController->SelectedTower->Price;
		PlayerController->SelectedTower = nullptr;
		bIsAvailable = false;
	}

	else
	{
		PlayerController->DisplayTowerWidget();
	}

}

void ATower::InitTower(ETowerName TowerName)
{
	switch (TowerName)
	{
		case ETowerName::Lich:
			Attack = 5;
			AttackSpeed = 2.0;
			Price = 50;
			TowerMesh = static_cast<USkeletalMeshComponent*>(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/UndeadPack/Lich/Mesh/SK_Lich.SK_Lich'")).Object);
			IdleAnimation = static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/Lich/Animations/Anim_Idle.Anim_Idle'")).Object);
			SpawnAnimation = static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/Lich/Animations/Anim_Emergence.Anim_Emergence'")).Object);
			AttackAnimations.Add(static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/Lich/Animations/Anim_Call.Anim_Call'")).Object));
			break;
		case ETowerName::Skeleton:
			Attack = 10;
			AttackSpeed = 5.0;
			Price = 20;
			TowerMesh = static_cast<USkeletalMeshComponent*>(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/UndeadPack/SkeletonEnemy/Mesh/SK_Skeleton.SK_Skeleton'")).Object);
			break;
		case ETowerName::Ghoul:
			Attack = 25;
			AttackSpeed = 4.0;
			Price = 15;
			break;
		case ETowerName::Goblin:
			Attack = 15;
			AttackSpeed = 3.0;
			Price = 10;
			break;
		case ETowerName::Zombie:
			Attack = 10;
			AttackSpeed = 2.0;
			Price = 5;
			break;
	}
}

