// Fill out your copyright notice in the Description page of Project Settings.


#include "Chest.h"
#include "InventoryComponent.h"


AChest::AChest() {
	Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory");
	Inventory->Capacity = 20;

}

void AChest::Interact(AMyProjectCharacter* Character)
{
	OnOpen(this);
}


