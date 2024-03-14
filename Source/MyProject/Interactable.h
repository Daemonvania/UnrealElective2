// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Interactable.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AInteractable : public AStaticMeshActor
{
	GENERATED_BODY()
	
public: 
	virtual void Interact(class AMyProjectCharacter* Character);


	void Tick(float DeltaTime);

	UFUNCTION(BlueprintImplementableEvent) void OnInteract(class AMyProjectCharacter* Character);
};

