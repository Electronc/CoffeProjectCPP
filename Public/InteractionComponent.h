// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"

class APlayerControllerBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COFFEPROJECT_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractionComponent();

    UFUNCTION(BlueprintCallable)
	void InitComponnent(ACharacter* PlayerCharacter, APlayerController* PlayerController);

    UFUNCTION(BlueprintCallable)
	void SetCanCheckInteraction(bool CanCheck);

    UFUNCTION(BlueprintCallable)
	void TryToInteract();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	AActor* CurrentTargetActor = nullptr;

	UFUNCTION()
	void CheckCurrentActor();

    UPROPERTY(EditAnywhere)
	bool CanCheckInteraction = false;

    UPROPERTY(EditAnywhere)
	ACharacter* LocalPlayerCharacter;

	UPROPERTY(EditAnywhere)
	APlayerController* LocalPlayerController;

	UPROPERTY(EditAnywhere)
	APlayerControllerBase* CastedPlayerController;

    UFUNCTION()
	void OnLoseActor();


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
