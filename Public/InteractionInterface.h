// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COFFEPROJECT_API IInteractionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractState")
    bool GetCanInteract() const; virtual bool GetCanInteract_Implementation() const { return false; }

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractState")
    FString GetInteractText() const; virtual FString GetInteractText_Implementation() const { return ""; }

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "InteractionEvent")
    void OnInteraction(APlayerController* PlayerController);
};
