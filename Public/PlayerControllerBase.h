// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

class UInteractionComponent;

UCLASS()
class COFFEPROJECT_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

	public:
	APlayerControllerBase();

	UFUNCTION(BlueprintNativeEvent, Category = "Widget")
	void CreateWidgetOrDestroy(bool bShouldCreate, const FString& WidgetText);

	void CreateWidgetOrDestroy_Implementation(bool bShouldCreate, const FString& WidgetText);



	protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UInteractionComponent* InteractionComponent = nullptr;

	virtual void SetupInputComponent() override;

	UFUNCTION()
	void TryToMakeInteraction();

	UFUNCTION(BlueprintNativeEvent, Category = "Interaction")
	void TryToTakeOutBottle();

	void TryToTakeOutBottle_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category = "Interaction")
	void TryToMakeObjectActionPressed();

	void TryToMakeObjectActionPressed_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category = "Interaction")
	void TryToMakeObjectActionReleased();

	void TryToMakeObjectActionReleased_Implementation();
	
};
