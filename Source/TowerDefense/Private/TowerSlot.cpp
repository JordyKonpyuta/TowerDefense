// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerSlot.h"

#include "CustomPlayerController.h"
#include "Tower_Child_Ghoul.h"
#include "Tower_Child_Goblin.h"
#include "Tower_Child_Lich.h"
#include "Tower_Child_Skeleton.h"
#include "Tower_Child_Zombie.h"
#include "Components/ArrowComponent.h"

// Sets default values
ATowerSlot::ATowerSlot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Pillar = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pillar"));
	TowerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TowerMesh"));
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	RootComponent = Pillar;
	TowerMesh->SetupAttachment(RootComponent);
	Arrow->SetupAttachment(RootComponent);
	TowerMesh->SetVisibility(false);
	Pillar->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);

	TowerMeshes[0] = static_cast<USkeletalMeshComponent*>(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/UndeadPack/Zombie/Mesh/SK_Zombie.SK_Zombie'")).Object);
	TowerMeshes[1] = static_cast<USkeletalMeshComponent*>(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/UndeadPack/Ghoul/Mesh/SK_Ghoul_Full.SK_Ghoul_Full'")).Object);
	TowerMeshes[2] = static_cast<USkeletalMeshComponent*>(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/UndeadPack/EnemyGoblin/Mesh/SM_EnemyGoblin.SM_EnemyGoblin'")).Object);
	TowerMeshes[3] = static_cast<USkeletalMeshComponent*>(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/UndeadPack/SkeletonEnemy/Mesh/SK_Skeleton.SK_Skeleton'")).Object);
	TowerMeshes[4] = static_cast<USkeletalMeshComponent*>(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/UndeadPack/Lich/Mesh/SK_Lich.SK_Lich'")).Object);

}

// Called when the game starts or when spawned
void ATowerSlot::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<ACustomPlayerController>(GetWorld()->GetFirstPlayerController());
	
}

// Called every frame
void ATowerSlot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATowerSlot::SetTowerMesh(AActor* TouchedActor)
{
	if (bIsAvailable)
	{
		TowerMesh->SetVisibility(true);
		switch (PlayerController->TowerType)
		{
			case ETowerType::Zombie:
				TowerMesh = TowerMeshes[0];
				break;

			case ETowerType::Ghoul:
				TowerMesh = TowerMeshes[1];
				break;

			case ETowerType::Goblin:
				TowerMesh = TowerMeshes[2];
				break;

			case ETowerType::Skeleton:
				TowerMesh = TowerMeshes[3];
				break;

			case ETowerType::Lich:
				TowerMesh = TowerMeshes[4];
				break;
				
			default:
				break;
		}
		
		for (int i = 0; i < TowerMesh->GetNumMaterials(); i++)
		{
			TowerMesh->SetMaterial(i, (ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Script/Engine.Material'/Game/Assets/M_PreviewTower.M_PreviewTower'")).Object));
		}
	}
}

void ATowerSlot::SelectTowerType_Implementation()
{
}

void ATowerSlot::OnUnhovered(AActor* TouchedActor)
{
	if (PlayerController->bIsInPlaceTowerMode)
		TowerMesh->SetVisibility(false);
}

void ATowerSlot::OnClicked()
{
	if (PlayerController->bIsInPlaceTowerMode)
	{
		if (bIsAvailable)
		{
			switch (PlayerController->TowerType)
			{
			case ETowerType::Zombie:
				TowerRef = GetWorld()->SpawnActor<ATower_Child_Zombie>(Arrow->GetRelativeLocation(), Arrow->GetRelativeRotation());
				PlayerController->Gold = PlayerController->Gold - TowerRef->Price;
				TowerMesh->SetVisibility(false);
				break;

			case ETowerType::Ghoul:
				TowerRef = GetWorld()->SpawnActor<ATower_Child_Ghoul>(Arrow->GetRelativeLocation(), Arrow->GetRelativeRotation());
				PlayerController->Gold = PlayerController->Gold - TowerRef->Price;
				TowerMesh->SetVisibility(false);
				break;

			case ETowerType::Goblin:
				TowerRef = GetWorld()->SpawnActor<ATower_Child_Goblin>(Arrow->GetRelativeLocation(), Arrow->GetRelativeRotation());
				PlayerController->Gold = PlayerController->Gold - TowerRef->Price;
				TowerMesh->SetVisibility(false);
				break;

			case ETowerType::Lich:
				TowerRef = GetWorld()->SpawnActor<ATower_Child_Lich>(Arrow->GetRelativeLocation(), Arrow->GetRelativeRotation());
				PlayerController->Gold = PlayerController->Gold - TowerRef->Price;
				TowerMesh->SetVisibility(false);
				break;

			case ETowerType::Skeleton:
				TowerRef = GetWorld()->SpawnActor<ATower_Child_Skeleton>(Arrow->GetRelativeLocation(), Arrow->GetRelativeRotation());
				PlayerController->Gold = PlayerController->Gold - TowerRef->Price;
				TowerMesh->SetVisibility(false);
				break;
			
			default:
				break;
			}
		}
	}

	else
	{
		PlayerController->DisplayTowerWidget();
	}
}


