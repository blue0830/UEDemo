// Fill out your copyright notice in the Description page of Project Settings.


#include "SprintAbility.h"
#include "GameplayEffect/SprintCooldown.h"

USprintAbility::USprintAbility()
{
	CooldownGameplayEffectClass = USprintCooldown::StaticClass();
	
}

void USprintAbility::ApplyCooldown(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) const
{
	UGameplayEffect* CooldownEffect = GetCooldownGameplayEffect();
	if (CooldownEffect)
	{
		FGameplayEffectSpecHandle CooldownEffectSpecHandle = MakeOutgoingGameplayEffectSpec(CooldownEffect->GetClass(),GetAbilityLevel());
		//CooldownEffectSpecHandle.Data.Get()->DynamicGrantedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Cooldown.TestSprint")));
		CooldownEffectSpecHandle.Data.Get()->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("Cooldown.TestSprint")),1);
		ApplyGameplayEffectSpecToOwner(Handle,ActorInfo,ActivationInfo,CooldownEffectSpecHandle);
	}
}

void USprintAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Sprint Ability Activated"));
	UE_LOG(LogTemp,Log,TEXT("Sprint Ability Activate ..."));
	//EndAbility(Handle,ActorInfo,ActivationInfo,false,false);
	K2_EndAbility();
}
