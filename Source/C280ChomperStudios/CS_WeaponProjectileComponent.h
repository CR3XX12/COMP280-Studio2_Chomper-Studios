// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "CS_WeaponProjectileComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class C280CHOMPERSTUDIOS_API UCS_WeaponProjectileComponent : public USceneComponent
{
	GENERATED_BODY()

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Projectile", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class ACS_BaseWeaponProjectile> ProjectileClass;

	// Declare the input mapping context for the basic actions (movement, interaction, etc.)

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputMappingContext> WeaponMappingContext;

	/** Fire Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ThrowAction;

public:	
	// Sets default values for this component's properties
	UCS_WeaponProjectileComponent();

	// Changes the spawned projectile class
	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void SetProjectileClass(TSubclassOf<class ACS_BaseWeaponProjectile> NewProjectileClass);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Throw the projectile
	void Throw();

	// Throw the projectile on the server
	UFUNCTION(Server, Reliable)
	void Throw_Server();


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
