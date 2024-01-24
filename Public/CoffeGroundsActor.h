// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoffeGroundsActor.generated.h"

class ACoffeMachineBase;
UCLASS()
class COFFEPROJECT_API ACoffeGroundsActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ACoffeGroundsActor();

	UPROPERTY(EditAnywhere, Category = "Coffe Machine")
	ACoffeMachineBase* CoffeMachine = nullptr;

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
