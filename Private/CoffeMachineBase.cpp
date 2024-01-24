// Fill out your copyright notice in the Description page of Project Settings.


#include "CoffeMachineBase.h"
#include "ContainersComponent.h"
#include "CoffeGroundsActor.h"

// Sets default values
ACoffeMachineBase::ACoffeMachineBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ContainerComponent = CreateDefaultSubobject<UContainersComponent>("Container Component");

}

// Called when the game starts or when spawned
void ACoffeMachineBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoffeMachineBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

