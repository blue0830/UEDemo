#include "UDAttributeSet.h"

#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UUDAttributeSet::UUDAttributeSet()
{
	Health.SetCurrentValue(100.0f);
	MaxHealth.SetCurrentValue(100.0f);
	Stamina.SetCurrentValue(100.0f);
	MaxStamina.SetCurrentValue(100.0f);
	AttackPower.SetCurrentValue(10.0f);
	Defense.SetCurrentValue(10.0f);
}

void UUDAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UUDAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUDAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUDAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUDAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUDAttributeSet, AttackPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUDAttributeSet, Defense, COND_None, REPNOTIFY_Always);
}

void UUDAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
    if(Attribute == GetHealthAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, MaxHealth.GetCurrentValue());
    }
    else if(Attribute == GetStaminaAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, MaxStamina.GetCurrentValue());
    }
    else if(Attribute == GetAttackPowerAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, 100.0f);
    }
}

void UUDAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);
    UE_LOG(LogTemp, Log, TEXT("Attribute: %s, OldValue: %f, NewValue: %f"), *Attribute.AttributeName, OldValue, NewValue);
}

void UUDAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUDAttributeSet, Health, OldHealth);
}

void UUDAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUDAttributeSet, MaxHealth, OldMaxHealth);
}

void UUDAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUDAttributeSet, Stamina, OldStamina);
}

void UUDAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) 
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUDAttributeSet, MaxStamina, OldMaxStamina);
}

void UUDAttributeSet::OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUDAttributeSet, AttackPower, OldAttackPower);
}

void UUDAttributeSet::OnRep_Defense(const FGameplayAttributeData& OldDefense)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUDAttributeSet, Defense, OldDefense);
}