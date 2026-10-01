// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "EnemyCharacter.generated.h"

class UAbilitySystemComponent;
class UEnemyAttributeSet;

UCLASS()
class UE5_GAS_TEST_API AEnemyCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS", meta = (AllowPrivateAccess = "true"))
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS", meta = (AllowPrivateAccess = "true"))
	UEnemyAttributeSet* EnemyAttributeSet;

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }

	FORCEINLINE UEnemyAttributeSet* GetEnemyAttributeSet() const { return EnemyAttributeSet; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
