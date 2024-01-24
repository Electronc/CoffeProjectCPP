// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionComponent.h"
#include "InteractionInterface.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.h"
#include "DrawDebugHelpers.h"


// Sets default values for this component's properties
UInteractionComponent::UInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UInteractionComponent::InitComponnent(ACharacter* PlayerCharacter, APlayerController* PlayerController)
{
	LocalPlayerCharacter = PlayerCharacter;
	LocalPlayerController = PlayerController;
	CastedPlayerController = Cast<APlayerControllerBase>(PlayerController);
}

void UInteractionComponent::SetCanCheckInteraction(bool CanCheck)
{
	UE_LOG(LogTemp, Warning, TEXT("CAN CHECK CHANGED"));
	CanCheckInteraction = CanCheck;
	OnLoseActor();
}

void UInteractionComponent::TryToInteract()
{
	if(CurrentTargetActor==nullptr)
	{
		return;
	}

	if (CurrentTargetActor->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()))
	{
   		IInteractionInterface::Execute_OnInteraction(CurrentTargetActor, LocalPlayerController);
	}


}

// Called when the game starts
void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UInteractionComponent::CheckCurrentActor()
{
  FVector CameraLocation;
  FRotator CameraRotation;
  LocalPlayerController->GetPlayerViewPoint(CameraLocation, CameraRotation);
  FVector End = CameraLocation + CameraRotation.Vector() * 500.0f;
  FHitResult HitResult;
  FCollisionQueryParams CollisionParams;
  bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult
  											 ,CameraLocation
											 , End
											 , ECC_Visibility
											 , CollisionParams);
 
  if(bHit)
  {
	AActor* HittedActor = HitResult.GetActor();
	if(HittedActor!=nullptr&&HittedActor->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()))
	{
		CurrentTargetActor = HittedActor;
		UE_LOG(LogTemp, Warning, TEXT("EKSPRES HITED"));
		CastedPlayerController->CreateWidgetOrDestroy(true, IInteractionInterface::Execute_GetInteractText(CurrentTargetActor));
	}else
	{
		OnLoseActor();
	}
	
  }else
  {
       OnLoseActor();
  }
  
  //DrawDebugLine(GetWorld(), CameraLocation, End, FColor::Green, false, 2.0f, 2, 1.0f);
        



}

void UInteractionComponent::OnLoseActor()
{
	CurrentTargetActor = nullptr;
	UE_LOG(LogTemp, Warning, TEXT("LOSE ACTOR"));
	CastedPlayerController->CreateWidgetOrDestroy(false, "");
}

void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  	 if(CanCheckInteraction)
  	 {
    	CheckCurrentActor();
  	 }
    

}

