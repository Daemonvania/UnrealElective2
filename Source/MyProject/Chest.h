// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Chest.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AChest : public AInteractable
{
	GENERATED_BODY()


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UInventoryComponent* Inventory;

	AChest();

	virtual void Interact(AMyProjectCharacter* Character) override;

public: 
		UFUNCTION(BlueprintImplementableEvent) void OnOpen(class AChest* Chest);

};
