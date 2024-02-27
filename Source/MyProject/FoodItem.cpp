// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItem.h"
#include "MyProjectCharacter.h"

void UFoodItem::Use(AMyProjectCharacter* Character)
{
	if (Character) {
		Character->Health += HealthToHeal;
	}
}
