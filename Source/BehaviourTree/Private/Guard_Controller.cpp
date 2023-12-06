// Fill out your copyright notice in the Description page of Project Settings.


#include "Guard_Controller.h"

#include "NavigationSystem.h"
#include "Repeater.h"
#include "TestBehaviour.h"
#include "UObject/Class.h"

void AGuard_Controller::BeginPlay()
{
	Super::BeginPlay();
	
	NavArea = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);

	BT = new Repeater(10, new TestBehaviour("test the repeater"));
}

void AGuard_Controller::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	Status state = BT->tick();
}
