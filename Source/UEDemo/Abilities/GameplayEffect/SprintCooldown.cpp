// Fill out your copyright notice in the Description page of Project Settings.


#include "SprintCooldown.h"

USprintCooldown::USprintCooldown()
{
	DurationPolicy = EGameplayEffectDurationType::HasDuration;
	DurationMagnitude = FGameplayEffectModifierMagnitude(FSetByCallerFloat());
	//GrantedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.Sprint")));
	FGameplayTag GameplayTag = FGameplayTag::RequestGameplayTag(FName("Cooldown.Sprint"));
	//InheritableOwnedTagsContainer.Added(GameplayTag);
	InheritableOwnedTagsContainer.AddTag(GameplayTag);
}
