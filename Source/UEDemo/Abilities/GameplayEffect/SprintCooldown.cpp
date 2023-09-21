// Fill out your copyright notice in the Description page of Project Settings.


#include "SprintCooldown.h"

USprintCooldown::USprintCooldown()
{
	DurationPolicy = EGameplayEffectDurationType::HasDuration;
	FSetByCallerFloat Value = FSetByCallerFloat();
	Value.DataTag = FGameplayTag::RequestGameplayTag(FName("Cooldown.TestSprint"));
	DurationMagnitude = FGameplayEffectModifierMagnitude(Value);
	//Modifiers.Add()
	
	
	//GrantedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Ability.Sprint")));
	FGameplayTag GameplayTag = FGameplayTag::RequestGameplayTag(FName("Cooldown.Sprint"));
	//InheritableOwnedTagsContainer.Added(GameplayTag);
	InheritableOwnedTagsContainer.AddTag(GameplayTag);
}
