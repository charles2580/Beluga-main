// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CatCreature.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CatPlayer.generated.h"

/**
 * 
 */

UCLASS()
class BELUGA_API UCatPlayer : public UCreature
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable)
		bool Attack(class UCatMonster* Monster);
public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "디폴트")
		int32 AttackPower = 30;

	UPROPERTY()
		bool IsDead;
};

