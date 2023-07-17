// Fill out your copyright notice in the Description page of Project Settings.


#include "Cat/CatPlayer.h"
#include "CatMonster.h"

bool UCatPlayer::Attack(class UCatMonster* Monster)
{
	FString MonsterName = Name.ToString();
	FString AttackMessage = FString::Printf(TEXT("%s을 %d만큼 공격합니다."), *MonsterName, AttackPower);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, AttackMessage);

	IsDead = Monster->TakeDamage(AttackPower);
	return IsDead;
}