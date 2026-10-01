// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayCueNotify_Burn.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

AGameplayCueNotify_Burn::AGameplayCueNotify_Burn()
{
	bAutoDestroyOnRemove = true;
}

bool AGameplayCueNotify_Burn::WhileActive_Implementation(AActor * MyTarget, const FGameplayCueParameters & Parameters)
{
	if (!MyTarget || !BurnEffect || BurnComponent)
	{
		return false;
	}

	FVector SpawnLocation = MyTarget->GetActorLocation();
	if (const FHitResult* HitResult = Parameters.EffectContext.GetHitResult())
	{
		SpawnLocation = HitResult->ImpactPoint;
	}

	BurnComponent = UNiagaraFunctionLibrary::SpawnSystemAttached(
		BurnEffect, MyTarget->GetRootComponent(), NAME_None,
		SpawnLocation, FRotator::ZeroRotator, EAttachLocation::KeepWorldPosition, false);

	return true;
}

bool AGameplayCueNotify_Burn::OnRemove_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters)
{
	if (BurnComponent)
	{
		BurnComponent->DestroyComponent();
		BurnComponent = nullptr;
	}

	return true;
}
