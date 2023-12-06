// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Behaviour.h"

class AAIController;
/**
 * 
 */
class BEHAVIOURTREE_API Patrol : public Behaviour
{
private:
	float MoveSpeed;
	FVector TargetPosition;
	FString TargetPosKey;
	AAIController* AI;
public:
	Patrol(AAIController* AI, float MoveSpeed, FString TargetPosKey);
	~Patrol();

protected:
	virtual void OnInitialize() override;
	virtual Status OnUpdate() override;
};
