// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower_Child_Ghoul.h"

void ATower_Child_Ghoul::AttackEnnemy()
{
	Super::AttackEnnemy();
}

void ATower_Child_Ghoul::InitTower()
{
	Super::InitTower();
	
	Attack = 25;
	AttackSpeed = 4;
	Price = 15;

	TowerMesh = static_cast<USkeletalMeshComponent*>(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/UndeadPack/Ghoul/Mesh/SK_Ghoul_Full.SK_Ghoul_Full'")).Object);
	IdleAnimation = static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/Ghoul/Animations/Anim_Idle.Anim_Idle'")).Object);
	SpawnAnimation = static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/Ghoul/Animations/Anim_Jump_End.Anim_Jump_End'")).Object);
	AttackAnimations.Add(static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/Ghoul/Animations/Anim_Attack_Left.Anim_Attack_Left'")).Object));
	AttackAnimations.Add(static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/Ghoul/Animations/Anim_Attack_Right.Anim_Attack_Right'")).Object));
	AgrouAnimation = static_cast<UAnimSequence*>(ConstructorHelpers::FObjectFinder<UAnimSequence>(TEXT("/Script/Engine.AnimSequence'/Game/Assets/UndeadPack/Ghoul/Animations/Anim_Agr.Anim_Agr'")).Object);
}
