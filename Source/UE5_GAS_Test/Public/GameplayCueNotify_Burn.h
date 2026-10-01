// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayCueNotify_Actor.h"
#include "GameplayCueNotify_Burn.generated.h"

class UNiagaraSystem;
class UNiagaraComponent;

/**
 * 
 */
UCLASS()
class UE5_GAS_TEST_API AGameplayCueNotify_Burn : public AGameplayCueNotify_Actor
{
	GENERATED_BODY()
	
public:
	AGameplayCueNotify_Burn();

	virtual bool WhileActive_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters) override;
	virtual bool OnRemove_Implementation(AActor* MyTarget, const FGameplayCueParameters& Parameters) override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Burn")
	UNiagaraSystem* BurnEffect;

	UNiagaraComponent* BurnComponent;

};
