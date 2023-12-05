// Fill out your copyright notice in the Description page of Project Settings.


#include "Guard_Controller.h"
#include "NavigationSystem.h"


void AGuard_Controller::BeginPlay()
{
	Super::BeginPlay();
	
	NavArea = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
}
