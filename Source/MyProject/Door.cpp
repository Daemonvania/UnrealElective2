// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Interactable.h"

ADoor::ADoor() {

	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorFrame->SetupAttachment(RootComponent);

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(DoorFrame);

	if (CurveFloat) {
		Timeline.SetTimelineLength(5.0f);
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindDynamic(this, &ADoor::OpenDoor);
		Timeline.AddInterpFloat(CurveFloat, TimelineProgress);
	}
}

void ADoor::BeginPlay()
{
}


void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Yellow, "lol");

	Timeline.TickTimeline(DeltaTime);
}


void ADoor::Interact(AMyProjectCharacter* Character)
{
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Yellow, "lol");


	if (CurveFloat) {
	}

	if (bIsDoorClosed) {
		Timeline.Play();
	}
	else {
		Timeline.Reverse();
	}

	bIsDoorClosed = !bIsDoorClosed;
}

void ADoor::OpenDoor(float Value)
{
	GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Yellow, "lol");

	FRotator Rot = FRotator(0.f, DoorRotateAngle * Value, 0.f);

	Door->SetRelativeRotation(Rot);
}
