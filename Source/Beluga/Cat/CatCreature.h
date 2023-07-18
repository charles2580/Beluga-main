// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CatCreature.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class UCreature : public UObject
{
	GENERATED_BODY()
public:
	UCreature();

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
		void HongikUniv(int32 In, int32& Result);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void Init();
public:

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "디폴트")
		FName Name;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "디폴트")
		int32 MaxHP;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "디폴트")
		int32 CurrentHP;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "디폴트")
		FName Name_0;
};
