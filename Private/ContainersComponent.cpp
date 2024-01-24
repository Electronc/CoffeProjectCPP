// Fill out your copyright notice in the Description page of Project Settings.


#include "ContainersComponent.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UContainersComponent::UContainersComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UContainersComponent::UpdateCurrentWaterLevel()
{
	CurrentWaterLevel = UpdateLevelValue(CurrentWaterLevel, TargetCurrentWaterLevel);
}

void UContainersComponent::UpdateCurrentCoffeLevel()
{
	CurrentCoffeGroundsLevel = UpdateLevelValue(CurrentCoffeGroundsLevel, TargetCurrentCoffeGroundsLevel);
}

float UContainersComponent::UpdateLevelValue(float Value, float Target)
{
	if(Value==Target){
       
	}else if(Value<Target){
      Value += 0.2f;
	}else{
      Value -= 0.2f;
	}
    return Value;
}

void UContainersComponent::SetNewTargetWaterLevel(float NewTargetWaterLevel)
{
	TargetCurrentWaterLevel = NewTargetWaterLevel;
}

void UContainersComponent::SetNewTargetCoffeGroundsLevel(float NewTargetCoffeGroundsLevel)
{
	TargetCurrentCoffeGroundsLevel = NewTargetCoffeGroundsLevel;
}

void UContainersComponent::SetBlockedCoffeUpdate(bool blocked)
{
	BlockedCoffeUpdate = blocked;
}

float UContainersComponent::GetWaterLevel() 
{
    return CurrentWaterLevel;
}

float UContainersComponent::GetCoffeGroundsLevel() 
{
    return CurrentCoffeGroundsLevel;
}

void UContainersComponent::AddToTargetWaterLevel(float Value)
{
	if(FMath::IsNearlyEqual(TargetCurrentWaterLevel, 100.0f, 0.1f))
	{
       TargetCurrentWaterLevel = 100.0f;
	}else if(TargetCurrentWaterLevel>100.0f)
	{
       TargetCurrentWaterLevel = 100.0f;
	}else{
		TargetCurrentWaterLevel+=Value;
	}
}

// Called when the game starts
void UContainersComponent::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void UContainersComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	UpdateCurrentWaterLevel();

	if(!BlockedCoffeUpdate)
	{
      UpdateCurrentCoffeLevel();
	}
	
}

