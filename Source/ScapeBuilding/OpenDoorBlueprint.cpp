// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoorBlueprint.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UOpenDoorBlueprint::UOpenDoorBlueprint()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoorBlueprint::BeginPlay()
{
	Super::BeginPlay();

	if (!Opener)
	{
		Opener = GetWorld()->GetFirstPlayerController()->GetPawn();
	}
}


// Called every frame
void UOpenDoorBlueprint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
	if (PressurePlate && PressurePlate->IsOverlappingActor(Opener)) 
	{
		OnOpen.Broadcast();
	}
	else 
	{
		OnClose.Broadcast();
	}
}

