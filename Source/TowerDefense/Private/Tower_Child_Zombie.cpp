// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower_Child_Zombie.h"

void ATower_Child_Zombie::AttackEnnemy()
{
	Super::AttackEnnemy();
}

void ATower_Child_Zombie::InitTower()
{
	Super::InitTower();

	Attack = 10;
	AttackSpeed = 2;
	Price = 5;

	TowerMesh = static_cast<USkeletalMeshComponent*>(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/UndeadPack/Zombie/Mesh/SK_Zombie.SK_Zombie'")).Object);
	IdleAnimation = static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/Zombie/Animations/Anim_Idle.Anim_Idle'")).Object);
	SpawnAnimation = static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/Zombie/Animations/Anim_Death.Anim_Death'")).Object);
	AttackAnimations.Add(static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/Zombie/Animations/Anim_Attack1.Anim_Attack1'")).Object));
	AttackAnimations.Add(static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/Zombie/Animations/Anim_Attack2.Anim_Attack2'")).Object));
	AgrouAnimation = nullptr;
}
