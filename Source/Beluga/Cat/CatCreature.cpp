// Fill out your copyright notice in the Description page of Project Settings.


#include "Cat/CatCreature.h"

UCreature::UCreature()
{
	Name = "피조물";
}

void UCreature::HongikUniv(int32 In, int32& Result)
{

}

void UCreature::Init_Implementation()
{
	MaxHP = CurrentHP;
	FString CreatureName = Name.ToString();
	FString SpawnCreature = FString::Printf(TEXT("%s 생성되었습니다"), *CreatureName);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, SpawnCreature);
}
