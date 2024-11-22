// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower_Child_Skeleton.h"

void ATower_Child_Skeleton::InitTower()
{
	Super::InitTower();

	Attack = 10;
	AttackSpeed = 5;
	Price = 20;

	TowerMesh = static_cast<USkeletalMeshComponent*>(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/UndeadPack/SkeletonEnemy/Mesh/SK_Skeleton.SK_Skeleton'")).Object);
	IdleAnimation = static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/SkeletonEnemy/Animations/Anim_Idle.Anim_Idle'")).Object);
	SpawnAnimation = static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/SkeletonEnemy/Animations/Anim_Jump_End.Anim_Jump_End'")).Object);
	AttackAnimations.Add(static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/SkeletonEnemy/Animations/Anim_Attack_1.Anim_Attack_1'")).Object));
	AttackAnimations.Add(static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/SkeletonEnemy/Animations/Anim_Attack_2.Anim_Attack_2'")).Object));
	AgrouAnimation = nullptr;
}

void ATower_Child_Skeleton::AttackEnnemy()
{
	Super::AttackEnnemy();
}
