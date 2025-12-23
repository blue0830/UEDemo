// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "UDAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class UEDEMO_API UUDAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UUDAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
	

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth);
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina);
	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina);
	UFUNCTION()
	void OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower);
	UFUNCTION()
	void OnRep_Defense(const FGameplayAttributeData& OldDefense);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	FGameplayAttributeData Health;
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UUDAttributeSet,Health);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Health);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Health);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	FGameplayAttributeData MaxHealth;
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UUDAttributeSet,MaxHealth);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(MaxHealth);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(MaxHealth);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	FGameplayAttributeData Stamina;
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UUDAttributeSet,Stamina);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Stamina);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Stamina);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	FGameplayAttributeData MaxStamina;
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UUDAttributeSet,MaxStamina);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(MaxStamina);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(MaxStamina);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FGameplayAttributeData AttackPower;
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UUDAttributeSet,AttackPower);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(AttackPower);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(AttackPower);
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Defense")
	FGameplayAttributeData Defense;
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UUDAttributeSet,Defense);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Defense);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Defense);
};