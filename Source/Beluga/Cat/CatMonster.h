// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CatCreature.h"
#include "Math/UnrealMathUtility.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CatMonster.generated.h"

/**
 * 
 */
UCLASS()
class BELUGA_API UCatMonster : public UCreature
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		bool TakeDamage(int32 Damage);

	UPROPERTY()
		bool IsDead;

private:
	UPROPERTY()
		bool Dead;
};
