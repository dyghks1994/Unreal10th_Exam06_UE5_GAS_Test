// Fill out your copyright notice in the Description page of Project Settings.


#include "FireballDamageExecution.h"
#include "AbilitySystemComponent.h"
#include "EnemyAttributeSet.h"
#include "GAS/GASGameplayTags.h"

void UFireballDamageExecution::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

	float Damage = Spec.GetSetByCallerMagnitude(GASTags::Data_Damage, false, 0.f);

	UAbilitySystemComponent* TargetASC = ExecutionParams.GetTargetAbilitySystemComponent();
	if (TargetASC && TargetASC->HasMatchingGameplayTag(GASTags::State_Burn))
	{
		Damage *= 2.f;
	}

	if (Damage > 0.f)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(UEnemyAttributeSet::GetDamageAttribute(), EGameplayModOp::AddBase, Damage));
	}
}
