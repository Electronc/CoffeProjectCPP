// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HandItem.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHandItem : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COFFEPROJECT_API IHandItem
{
	GENERATED_BODY()

    
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HandItem")
    void OnItemActionPressed();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "HandItem")
    void OnItemActionReleased();
};
