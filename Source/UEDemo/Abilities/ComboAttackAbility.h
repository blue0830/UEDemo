// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "../Types.h"
#include "ComboAttackAbility.generated.h"

/**
 * 
 */
UCLASS()
class UEDEMO_API UComboAttackAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UComboAttackAbility();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData);

protected:

	int32 AttackCount;
	int32 MaxAttackCount;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "AbilityInput")
		EAbilityInputId AbilityInputId;

	TArray<UAnimMontage*> AttackMontages;
};
