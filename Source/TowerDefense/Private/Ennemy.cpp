// Fill out your copyright notice in the Description page of Project Settings.


#include "Ennemy.h"

// Sets default values
AEnnemy::AEnnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	RootComponent = SkeletalMesh;

	SkeletalMesh = static_cast<USkeletalMeshComponent*>(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/UndeadPack/Zombie/Mesh/SK_Zombie.SK_Zombie'")).Object);

}

// Called when the game starts or when spawned
void AEnnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnnemy::OnDeath()
{
}

void AEnnemy::InitEnnemy()
{
}

