// Fill out your copyright notice in the Description page of Project Settings.


#include "EnnemySpawner.h"

#include "Ennemy.h"
#include "Components/ArrowComponent.h"

// Sets default values
AEnnemySpawner::AEnnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	RootComponent = Arrow;

}

// Called when the game starts or when spawned
void AEnnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(SpawnTimer , this , &AEnnemySpawner::SpawnEnnemy, 1.f,true);
	
}

// Called every frame
void AEnnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnnemySpawner::SpawnEnnemy()
{
	GetWorld()->SpawnActor<AEnnemy>(Arrow->GetRelativeLocation(), Arrow->GetRelativeRotation());
}



