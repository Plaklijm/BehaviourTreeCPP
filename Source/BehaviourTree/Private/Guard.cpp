// Fill out your copyright notice in the Description page of Project Settings.


#include "Guard.h"

#include "Components/TextRenderComponent.h"


// Sets default values
AGuard::AGuard()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Size and position set in the blueprint class
	StatusText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("StatusText"));
	StatusText->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	StatusText->SetHorizontalAlignment(EHTA_Center);
	// TODO: Initialize behaviour tree

}

// Called when the game starts or when spawned
void AGuard::BeginPlay()
{
	Super::BeginPlay();
	StatusText->SetText(FText::FromString("Default State"));

}

// Called every frame
void AGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AGuard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

