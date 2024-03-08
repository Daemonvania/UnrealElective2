// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemPickup.h"
#include "InventoryComponent.h"
#include "MyProjectCharacter.h"

void AItemPickup::OnInteract(AMyProjectCharacter* Character)
{
    if (Character)
    {
        AMyProjectCharacter* MyCharacter = Cast<AMyProjectCharacter>(Character);

        if (MyCharacter)
        {

            UInventoryComponent* InventoryComponent = Character->GetInventoryComponent();

            if (InventoryComponent)
            {
              
                InventoryComponent->AddItem(ItemToGive);
                this->Destroy();
            }
        }
    }
}
