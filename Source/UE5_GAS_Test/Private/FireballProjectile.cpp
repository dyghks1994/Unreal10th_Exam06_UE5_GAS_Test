// Fill out your copyright notice in the Description page of Project Settings.


#include "FireballProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"

// Sets default values
AFireballProjectile::AFireballProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->InitSphereRadius(15.f);
	CollisionComponent->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	RootComponent = CollisionComponent;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovementComponent->UpdatedComponent = CollisionComponent;
	ProjectileMovementComponent->InitialSpeed = 1500.f;
	ProjectileMovementComponent->MaxSpeed = 1500.f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->ProjectileGravityScale = 0.f;

	InitialLifeSpan = 3.f;
}

// Called when the game starts or when spawned
void AFireballProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionComponent->IgnoreActorWhenMoving(GetInstigator(), true);
	CollisionComponent->OnComponentHit.AddDynamic(this, &AFireballProjectile::OnHit);
}

void AFireballProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && OtherActor != GetInstigator())
	{
		if (UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(OtherActor))
		{
			// 대미지 적용 먼저, 첫 타격은 화염피해 X
			if (DamageEffectSpecHandle.IsValid())
			{
				TargetASC->ApplyGameplayEffectSpecToSelf(*DamageEffectSpecHandle.Data.Get());
			}

			// 화염상태 적용
			if (BurnEffectSpecHandle.IsValid())
			{
				BurnEffectSpecHandle.Data->GetContext().AddHitResult(Hit, true);
				TargetASC->ApplyGameplayEffectSpecToSelf(*BurnEffectSpecHandle.Data.Get());
			}
		}
	}

	Destroy();
}

// Called every frame
void AFireballProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

