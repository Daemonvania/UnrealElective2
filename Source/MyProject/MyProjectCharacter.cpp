// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyProjectCharacter.h"
#include "MyProjectProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Engine/LocalPlayer.h"
#include "Item.h"
#include "InventoryComponent.h"
#include "Interactable.h"
#include "Blueprint/UserWidget.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AMyProjectCharacter

AMyProjectCharacter::AMyProjectCharacter()
{
	// Character doesnt have a rifle at start
	bHasRifle = false;
	
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory");
	Inventory->Capacity = 20;

	Health = 10;


}

void AMyProjectCharacter::Tick(float DeltaTime) {
	InteractCheck();
}

void AMyProjectCharacter::UseItem(UItem* Item)
{
	if (Item) {
		Item->Use(this);
		Item->OnUse(this);  //BP EVENT
	}
}

void AMyProjectCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	if (GetController())
	{
		//todo createWidget Is called with a null class
		InteractWidget = CreateWidget(Cast<APlayerController>(GetController()), InteractWidgetClass);
		if (InteractWidget)
		{
			InteractWidget->AddToViewport(0);
			InteractWidget->SetVisibility(ESlateVisibility::Collapsed);
		}
	}
}

//////////////////////////////////////////////////////////////////////////// Input

void AMyProjectCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyProjectCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyProjectCharacter::Look);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}


void AMyProjectCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AMyProjectCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AMyProjectCharacter::SetHasRifle(bool bNewHasRifle)
{
	bHasRifle = bNewHasRifle;
}

bool AMyProjectCharacter::GetHasRifle()
{
	return bHasRifle;
}

void AMyProjectCharacter::InteractCheck() {
	Cast<APlayerController>(GetController())->GetPlayerViewPoint(ViewVector, ViewRotation);
	FVector VecDirection = ViewRotation.Vector() * 1000.f;
	FVector InteractEnd = ViewVector + VecDirection.GetSafeNormal() * 1000.f;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	GetWorld()->LineTraceSingleByChannel(InteractResult, ViewVector, InteractEnd, ECollisionChannel::ECC_Pawn, QueryParams); 
	//todo actual layer lol

	if (InteractWidget)
	{
		if (Cast<AInteractable>(InteractResult.GetActor())) {
			InteractWidget->SetVisibility(ESlateVisibility::Visible);
		}
		else {
			InteractWidget->SetVisibility(ESlateVisibility::Collapsed);
		}
	}
}



void AMyProjectCharacter::Interact()
{
	if (Cast<AInteractable>(InteractResult.GetActor())) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("PLEASE"));
	};
}