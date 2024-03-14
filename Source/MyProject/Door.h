// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include <Components/TimelineComponent.h>
#include "Door.generated.h"


/**
 * 
 */
UCLASS()
class MYPROJECT_API ADoor : public AInteractable
{
	GENERATED_BODY()
	
public:

	ADoor();

protected: 
	virtual void BeginPlay() override;


		virtual void Interact(AMyProjectCharacter* Character) override;


		FTimeline Timeline;

		UPROPERTY(EditAnywhere)
		UCurveFloat* CurveFloat;

		bool bIsDoorClosed = true;

		float DoorRotateAngle = 90.f;

		UFUNCTION() 
		void OpenDoor(float Value);


private: 
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UStaticMeshComponent* DoorFrame;
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* Door;


	void Tick(float DeltaTime);

};
