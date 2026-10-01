// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUDWidget.generated.h"


class UAbilitySystemComponent;
class UProgressBar;
class UTextBlock;
struct FOnAttributeChangeData;

/**
 * 
 */
UCLASS()
class UE5_GAS_TEST_API UPlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void InitWithASC(UAbilitySystemComponent* InASC);

protected:
	virtual void NativeDestruct() override;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* HealthText;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* ManaBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ManaText;

private:
	void OnHealthChanged(const FOnAttributeChangeData& Data);
	void OnManaChanged(const FOnAttributeChangeData& Data);

	void RefreshHealth();
	void RefreshMana();

	TWeakObjectPtr<UAbilitySystemComponent> ASC;
};
