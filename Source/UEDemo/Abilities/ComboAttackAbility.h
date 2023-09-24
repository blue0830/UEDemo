// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "../Types.h"
#include "AbilityBase.h"
#include "ComboAttackAbility.generated.h"

/**
 * 
 */
UCLASS()
class UEDEMO_API UComboAttackAbility : public UAbilityBase
{
	GENERATED_BODY()
	
public:
	UComboAttackAbility();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData);

protected:

	int32 AttackCount;
	int32 MaxAttackCount;

	TArray<UAbilityBase> AttackAbilities;
};
