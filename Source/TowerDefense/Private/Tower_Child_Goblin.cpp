// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower_Child_Goblin.h"

void ATower_Child_Goblin::AttackEnnemy()
{
	Super::AttackEnnemy();
}

void ATower_Child_Goblin::InitTower()
{
	Super::InitTower();

	Attack = 15;
	AttackSpeed = 3;
	Price = 10;

	TowerMesh = static_cast<USkeletalMeshComponent*>(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/UndeadPack/EnemyGoblin/Mesh/SM_EnemyGoblin.SM_EnemyGoblin'")).Object);
	IdleAnimation = static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/EnemyGoblin/Animations/Anim_Idle.Anim_Idle'")).Object);
	SpawnAnimation = static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/EnemyGoblin/Animations/Anim_Jump_Out.Anim_Jump_Out'")).Object);
	AttackAnimations.Add(static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/EnemyGoblin/Animations/Anim_Attack1.Anim_Attack1'")).Object));
	AttackAnimations.Add(static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/EnemyGoblin/Animations/Anim_Attack2.Anim_Attack2'")).Object));
	AgrouAnimation = static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/EnemyGoblin/Animations/Anim_Agr.Anim_Agr'")).Object);
}
