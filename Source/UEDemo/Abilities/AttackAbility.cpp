// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackAbility.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "GameplayAbilities/Public/AbilitySystemComponent.h"
#include "../UEDemoCharacter.h"

UAttackAbility::UAttackAbility()
{

}

void UAttackAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle,ActorInfo,ActivationInfo,TriggerEventData);

	
	//ActorInfo->AbilitySystemComponent->PlayMontage(this,ActivationInfo, MontageToPlay, 1.f, FName("None"));
	AUEDemoCharacter* Character = Cast<AUEDemoCharacter>(ActorInfo->AvatarActor.Get());
	TWeakObjectPtr< UAnimInstance> AnimInstance = Character->GetMesh()->GetAnimInstance();
	AnimInstance->OnMontageBlendingOut.AddDynamic(this, &UAttackAbility::OnMontageBlendingOut);
	AnimInstance->Montage_Play(MontageToPlay, 1.f, EMontagePlayReturnType::MontageLength, 0.f, true);

	
}

void UAttackAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle,ActorInfo,ActivationInfo, bReplicateEndAbility, bWasCancelled);
	AUEDemoCharacter* Character = Cast<AUEDemoCharacter>( ActorInfo->AvatarActor);
	if (Character)
	{
		Character->ResetCombo();
	}
}

void UAttackAbility::OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted)
{
	EndAbility(CurrentSpecHandle,CurrentActorInfo,CurrentActivationInfo,true,true);
}
