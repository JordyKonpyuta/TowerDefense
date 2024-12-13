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
	SetRootComponent(Pillar);
	TowerMesh->SetVisibility(false);
	Pillar->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);

}

// Called when the game starts or when spawned
void ATowerSlot::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<ACustomPlayerController>(GetWorld()->GetFirstPlayerController());

	// Pillar->OnClicked.AddDynamic(this, &ATowerSlot::OnClicked());
	
}

// Called every frame
void ATowerSlot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATowerSlot::SetTowerMesh()
{
	if (bIsAvailable)
	{
		TowerMesh->SetVisibility(true);
		switch (PlayerController->TowerType)
		{
			case ETowerType::Zombie:
				TowerMesh = static_cast<USkeletalMeshComponent*>(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/UndeadPack/Lich/Mesh/SK_Lich.SK_Lich'")).Object);
				break;

			case ETowerType::Ghoul:
				TowerMesh = static_cast<USkeletalMeshComponent*>(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/UndeadPack/Lich/Mesh/SK_Lich.SK_Lich'")).Object);
				break;

			case ETowerType::Goblin:
				TowerMesh = static_cast<USkeletalMeshComponent*>(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/UndeadPack/EnemyGoblin/Mesh/SM_EnemyGoblin.SM_EnemyGoblin'")).Object);
				break;

			case ETowerType::Lich:
				TowerMesh = static_cast<USkeletalMeshComponent*>(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/UndeadPack/Lich/Mesh/SK_Lich.SK_Lich'")).Object);
				break;

			case ETowerType::Skeleton:
				TowerMesh = static_cast<USkeletalMeshComponent*>(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/UndeadPack/Lich/Mesh/SK_Lich.SK_Lich'")).Object);
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

void ATowerSlot::OnUnhovered()
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


