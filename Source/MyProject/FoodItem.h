// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "FoodItem.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UFoodItem : public UItem
{
	GENERATED_BODY()

public: 	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item") float HealthToHeal;

protected:

	virtual void Use(AMyProjectCharacter* Character) override;
	
};


