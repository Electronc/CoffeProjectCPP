// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ContainersComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COFFEPROJECT_API UContainersComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

    UContainersComponent();

	UFUNCTION(BlueprintCallable)
	void UpdateCurrentWaterLevel();

	UFUNCTION(BlueprintCallable)
	void UpdateCurrentCoffeLevel();

	UFUNCTION(BlueprintCallable)
	float UpdateLevelValue(float Value, float Target);

    UFUNCTION(BlueprintCallable)
	void SetNewTargetWaterLevel(float NewTargetWaterLevel);

    UFUNCTION(BlueprintCallable)
	void SetNewTargetCoffeGroundsLevel(float NewTargetCoffeGroundsLevel);

	UFUNCTION(BlueprintCallable)
	void SetBlockedCoffeUpdate(bool blocked);

	UFUNCTION(BlueprintCallable)
	float GetWaterLevel();

	UFUNCTION(BlueprintCallable)
	float GetCoffeGroundsLevel();

	UFUNCTION(BlueprintCallable)
	void AddToTargetWaterLevel(float Value);

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float CurrentWaterLevel = 20.0f;

	UPROPERTY(EditAnywhere)
	float TargetCurrentWaterLevel = 20.0f;

	UPROPERTY(EditAnywhere)
	float CurrentCoffeGroundsLevel = 20.0f;

	UPROPERTY(EditAnywhere)
	float TargetCurrentCoffeGroundsLevel = 20.0f;

    UPROPERTY(EditAnywhere)
	bool BlockedCoffeUpdate = false;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
};
