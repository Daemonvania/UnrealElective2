// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTestActor.generated.h"

UCLASS()
class MYPROJECT_API AMyTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTestActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TestValues") int32 ValueA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TestValues") int32 ValueB;
	UFUNCTION(BlueprintCallable, Category = "TestFunctions") void CalculateValue();
	UFUNCTION(BlueprintImplementableEvent, Category = "TestFunctions") void OnValueCalculate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
