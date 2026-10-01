// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/PlayerHUDWidget.h"
#include "AbilitySystemComponent.h"
#include "PlayerAttributeSet.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UPlayerHUDWidget::InitWithASC(UAbilitySystemComponent* InASC)
{
	ASC = InASC;
	if (!InASC)
	{
		return;
	}

	InASC->GetGameplayAttributeValueChangeDelegate(UPlayerAttributeSet::GetHealthAttribute()).AddUObject(this, &UPlayerHUDWidget::OnHealthChanged);
	InASC->GetGameplayAttributeValueChangeDelegate(UPlayerAttributeSet::GetMaxHealthAttribute()).AddUObject(this, &UPlayerHUDWidget::OnHealthChanged);
	InASC->GetGameplayAttributeValueChangeDelegate(UPlayerAttributeSet::GetManaAttribute()).AddUObject(this, &UPlayerHUDWidget::OnManaChanged);
	InASC->GetGameplayAttributeValueChangeDelegate(UPlayerAttributeSet::GetMaxManaAttribute()).AddUObject(this, &UPlayerHUDWidget::OnManaChanged);

	// 초기값 갱신
	RefreshHealth();
	RefreshMana();
}

void UPlayerHUDWidget::NativeDestruct()
{
	if (UAbilitySystemComponent* InASC = ASC.Get())
	{
		InASC->GetGameplayAttributeValueChangeDelegate(UPlayerAttributeSet::GetHealthAttribute()).RemoveAll(this);
		InASC->GetGameplayAttributeValueChangeDelegate(UPlayerAttributeSet::GetMaxHealthAttribute()).RemoveAll(this);
		InASC->GetGameplayAttributeValueChangeDelegate(UPlayerAttributeSet::GetManaAttribute()).RemoveAll(this);
		InASC->GetGameplayAttributeValueChangeDelegate(UPlayerAttributeSet::GetMaxManaAttribute()).RemoveAll(this);
	}

	Super::NativeDestruct();
}

void UPlayerHUDWidget::OnHealthChanged(const FOnAttributeChangeData& Data)
{
	RefreshHealth();
}

void UPlayerHUDWidget::OnManaChanged(const FOnAttributeChangeData & Data)
{
	RefreshMana();
}

void UPlayerHUDWidget::RefreshHealth()
{
	UAbilitySystemComponent* InASC = ASC.Get();
	if (!InASC)
	{
		return;
	}

	const float Health = InASC->GetNumericAttribute(UPlayerAttributeSet::GetHealthAttribute());
	const float MaxHealth = InASC->GetNumericAttribute(UPlayerAttributeSet::GetMaxHealthAttribute());

	HealthBar->SetPercent(MaxHealth > 0.f ? Health / MaxHealth : 0.f);
	HealthText->SetText(FText::FromString(FString::Printf(TEXT("HP %.0f / %.0f"), Health, MaxHealth)));
}

void UPlayerHUDWidget::RefreshMana()
{
	UAbilitySystemComponent* InASC = ASC.Get();
	if (!InASC)
	{
		return;
	}

	const float Mana = InASC->GetNumericAttribute(UPlayerAttributeSet::GetManaAttribute());
	const float MaxMana = InASC->GetNumericAttribute(UPlayerAttributeSet::GetMaxManaAttribute());

	ManaBar->SetPercent(MaxMana > 0.f ? Mana / MaxMana : 0.f);
	ManaText->SetText(FText::FromString(FString::Printf(TEXT("MP %.0f / %.0f"), Mana, MaxMana)));
}
