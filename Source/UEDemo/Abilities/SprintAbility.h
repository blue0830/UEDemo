// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "SprintAbility.generated.h"

/**
 * 
 */
UCLASS()
class UEDEMO_API USprintAbility : public UGameplayAbility
{
	GENERATED_BODY()
	

public:
	USprintAbility();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
};
