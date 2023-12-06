// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Guard_Controller.generated.h"

/**
 * 
 */
UCLASS()
class BEHAVIOURTREE_API AGuard_Controller : public AAIController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

private:
	class UNavigationSystemV1* NavArea;

	class Behaviour* BT;
	
	UPROPERTY(EditAnywhere)
	TArray<FVector> Locations;
};
