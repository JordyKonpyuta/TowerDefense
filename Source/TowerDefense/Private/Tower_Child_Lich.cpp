// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower_Child_Lich.h"

void ATower_Child_Lich::InitTower()
{
	Super::InitTower();

	Attack = 5;
	AttackSpeed = 5;
	Price = 50;

	TowerMesh = static_cast<USkeletalMeshComponent*>(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/UndeadPack/Lich/Mesh/SK_Lich.SK_Lich'")).Object);
	IdleAnimation = static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/Lich/Animations/Anim_Idle.Anim_Idle'")).Object);
	SpawnAnimation = static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/Lich/Animations/Anim_Emergence.Anim_Emergence'")).Object);
	AttackAnimations.Add(static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/Lich/Animations/Anim_Call.Anim_Call'")).Object));
	AttackAnimations.Add(static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/Lich/Animations/Anim_Spell.Anim_Spell'")).Object));
	AgrouAnimation = nullptr;
}

void ATower_Child_Lich::AttackEnnemy()
{
	Super::AttackEnnemy();
}
