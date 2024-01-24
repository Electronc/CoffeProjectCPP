// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"
#include "InteractionComponent.h"
#include "Kismet/GameplayStatics.h"


APlayerControllerBase::APlayerControllerBase()
{
    InteractionComponent = CreateDefaultSubobject<UInteractionComponent>("Interaction Component");
}

void APlayerControllerBase::CreateWidgetOrDestroy_Implementation(bool bShouldCreate, const FString& WidgetText)
{

}

void APlayerControllerBase::BeginPlay()
{
   Super::BeginPlay();
   if(InteractionComponent){
      InteractionComponent->InitComponnent(UGameplayStatics::GetPlayerCharacter(GetWorld(),0), this);
      InteractionComponent->SetCanCheckInteraction(true);
   }else{
    UE_LOG(LogTemp, Warning, TEXT("NIE MA VALID KOMPONENTU BO TAK"));
   }
   
}

void APlayerControllerBase::TryToMakeInteraction()
{
    InteractionComponent->TryToInteract();
}

void APlayerControllerBase::TryToTakeOutBottle_Implementation()
{

}

void APlayerControllerBase::TryToMakeObjectActionPressed_Implementation()
{

}


void APlayerControllerBase::TryToMakeObjectActionReleased_Implementation()
{
    
}

void APlayerControllerBase::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAction("Interact", IE_Pressed, this, &APlayerControllerBase::TryToMakeInteraction);
    InputComponent->BindAction("Bottle", IE_Pressed, this, &APlayerControllerBase::TryToTakeOutBottle);
    InputComponent->BindAction("ObjectAction", IE_Pressed, this, &APlayerControllerBase::TryToMakeObjectActionPressed);
    InputComponent->BindAction("ObjectAction", IE_Released, this, &APlayerControllerBase::TryToMakeObjectActionReleased);
}
