// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "ItemPickup.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AItemPickup : public AInteractable
{
	GENERATED_BODY()


	UPROPERTY(EditDefaultsOnly, Instanced) class UItem* ItemToGive;

	virtual void OnInteract(AMyProjectCharacter* Character) override;
	//TODO make this wpork w blueprint like uproperty blueprintcallable
	
};
