// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"

void AInteractable::Interact(AMyProjectCharacter* Character)
{
	OnInteract(Character);
}
