// Fill out your copyright notice in the Description page of Project Settings.


#include "ComboAttackAbility.h"
#include "../UEDemoCharacter.h"

UComboAttackAbility::UComboAttackAbility()
{

}

void UComboAttackAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle,ActorInfo,ActivationInfo,TriggerEventData);

	

	AttackCount++;
}
