// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Door.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API ADoor : public AInteractable
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime);
	ADoor();

protected: 
	virtual void BeginPlay() override;
	virtual void OnInteract(AMyProjectCharacter* Character) override;

private: 
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UStaticMeshComponent* DoorFrame;
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* Door;
};
