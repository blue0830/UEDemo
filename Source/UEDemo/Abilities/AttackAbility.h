// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AbilityBase.h"
#include "AttackAbility.generated.h"

/**
 * 
 */
UCLASS()
class UEDEMO_API UAttackAbility : public UAbilityBase
{
	GENERATED_BODY()
	
public:
	UAttackAbility();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData);
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled);

private:
	UFUNCTION()
	void OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted);
	//UFUNCTION()
	//void OnMontageEnded();

protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
		UAnimMontage* MontageToPlay;
};
