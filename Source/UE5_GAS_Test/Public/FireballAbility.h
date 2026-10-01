// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "FireballAbility.generated.h"

class AFireballProjectile;
class UGameplayEffect;

/**
 * 
 */
UCLASS()
class UE5_GAS_TEST_API UFireballAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UFireballAbility();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Fireball")
	TSubclassOf<AFireballProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category = "Fireball")
	TSubclassOf<UGameplayEffect> DamageEffectClass;

	UPROPERTY(EditDefaultsOnly, Category = "Fireball")
	TSubclassOf<UGameplayEffect> BurnEffectClass;

	UPROPERTY(EditDefaultsOnly, Category = "Fireball")
	float Damage = 10.f;

	UPROPERTY(EditDefaultsOnly, Category = "Fireball")
	float SpawnForwardOffset = 100.f;

};
