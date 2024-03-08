// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Interactable.h"

void ADoor::Tick(float DeltaTime)
{
}

ADoor::ADoor() {
	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorFrame->SetupAttachment(RootComponent);

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(DoorFrame);
}

void ADoor::BeginPlay()
{
}

void ADoor::OnInteract(AMyProjectCharacter* Character)
{

}
