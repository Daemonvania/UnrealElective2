// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemDataStructs.generated.h"

/**
 * 
 */

UENUM() enum class EItemQuality : uint8 {
	Common,
	Rare,
	Epic,
	Legendary,
};


UENUM() enum class EITEMType : uint8 {
	Armor,
	Weapon,
	Item
};

USTRUCT() struct FItemTextData
{
	GENERATED_USTRUCT_BODY()

	FText Name;
	FText Desc;
	FText InteractionText;
	FText UsageText;
};

USTRUCT() struct FItemAssetData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere) UTexture2D* Icon;

	UPROPERTY(EditAnywhere) UStaticMesh* Mesh;
};

USTRUCT() struct FItemData : public FTableRowBase {
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, Category = "Item Data")	FName ID;

	UPROPERTY(EditAnywhere, Category = "Item Data")	EITEMType ItemType;

	UPROPERTY(EditAnywhere, Category = "Item Data")	EItemQuality ItemQuality;

	UPROPERTY(EditAnywhere, Category = "Item Data")	FItemTextData ItemTextData;

	UPROPERTY(EditAnywhere, Category = "Item Data")	FItemAssetData AssetData;
};