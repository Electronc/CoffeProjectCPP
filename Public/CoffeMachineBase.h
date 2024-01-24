// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoffeMachineBase.generated.h"

class UContainersComponent;
class ACoffeGroundsActor;
UCLASS()
class COFFEPROJECT_API ACoffeMachineBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoffeMachineBase();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UContainersComponent* ContainerComponent = nullptr;

	UPROPERTY(EditAnywhere, Category = "Grounds Container")
	ACoffeGroundsActor* CoffeGroundsActor = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
