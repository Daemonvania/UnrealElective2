// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Interactable.h"

void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Timeline.TickTimeline(DeltaTime);
}

ADoor::ADoor() {
	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorFrame->SetupAttachment(RootComponent);

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(DoorFrame);

	if (CurveFloat) {
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindDynamic(this, &ADoor::OpenDoor);
		Timeline.AddInterpFloat(CurveFloat, TimelineProgress);
	}
}

void ADoor::BeginPlay()
{
}

void ADoor::Interact(AMyProjectCharacter* Character)
{
	
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
	FRotator Rot = FRotator(0.f, DoorRotateAngle * Value, 0.f);

	Door->SetRelativeRotation(Rot);

	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, "M<AAAN");
}
