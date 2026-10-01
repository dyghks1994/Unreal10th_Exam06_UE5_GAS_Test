// Fill out your copyright notice in the Description page of Project Settings.


#include "FireballAbility.h"
#include "FireballProjectile.h"
#include "GAS/GASGameplayTags.h"
#include "GameFramework/Character.h"

UFireballAbility::UFireballAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	SetAssetTags(FGameplayTagContainer(GASTags::Ability_Fireball));
}

void UFireballAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo * ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData * TriggerEventData)
{
	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
		return;
	}

	ACharacter* Character = Cast<ACharacter>(ActorInfo->AvatarActor.Get());
	if (Character && ProjectileClass)
	{
		const FVector SpawnLocation = Character->GetActorLocation() + Character->GetActorForwardVector() * SpawnForwardOffset;
		const FTransform SpawnTransform(Character->GetActorRotation(), SpawnLocation);

		AFireballProjectile* Projectile = GetWorld()->SpawnActorDeferred<AFireballProjectile>(
			ProjectileClass, SpawnTransform, Character, Character, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

		if (Projectile)
		{
			if (DamageEffectClass)
			{
				FGameplayEffectSpecHandle DamageSpec = MakeOutgoingGameplayEffectSpec(DamageEffectClass, GetAbilityLevel());
				DamageSpec.Data->SetSetByCallerMagnitude(GASTags::Data_Damage, Damage);
				Projectile->DamageEffectSpecHandle = DamageSpec;
			}

			if (BurnEffectClass)
			{
				Projectile->BurnEffectSpecHandle = MakeOutgoingGameplayEffectSpec(BurnEffectClass, GetAbilityLevel());
			}

			Projectile->FinishSpawning(SpawnTransform);
		}
	}

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
