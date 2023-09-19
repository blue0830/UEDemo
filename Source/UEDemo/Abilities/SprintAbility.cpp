// Fill out your copyright notice in the Description page of Project Settings.


#include "SprintAbility.h"

void USprintAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Sprint Ability Activated"));
	UE_LOG(LogTemp,Log,TEXT("Sprint Ability Activate ..."));
}
