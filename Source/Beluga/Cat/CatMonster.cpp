// Fill out your copyright notice in the Description page of Project Settings.


#include "Cat/CatMonster.h"


bool UCatMonster::TakeDamage(int32 Damage)
{
	CurrentHP = FMath::Max(CurrentHP - Damage,0);

	if (CurrentHP == 0)
	{
		Dead = true;
	}

	if (Dead == true)
	{
		FString MonsterName = Name.ToString();
		FString DeadMessage = FString::Printf(TEXT("%s 죽음"), *MonsterName);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, DeadMessage);
	}

	IsDead = Dead;
	return IsDead;
}