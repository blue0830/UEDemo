// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "../Types.h"
#include "AbilityBase.generated.h"

/**
 * 
 */
UCLASS()
class UEDEMO_API UAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()
	
public:


	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "AbilityInput")
		EAbilityInputId AbilityInputId;
};
