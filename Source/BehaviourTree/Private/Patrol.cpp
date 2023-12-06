// Fill out your copyright notice in the Description page of Project Settings.


#include "Patrol.h"

#include "AIController.h"
#include "Navigation/PathFollowingComponent.h"


Patrol::Patrol(AAIController* AI, const float MoveSpeed, FString TargetPosKey)
{
	this->MoveSpeed = MoveSpeed;
	this->TargetPosKey = TargetPosKey;
	this->AI = AI;
}

Patrol::~Patrol()
{
}

void Patrol::OnInitialize()
{
	//set agent speed
	TargetPosition = BlackBoard->GetValue<FVector>(TargetPosKey);
}

Status Patrol::OnUpdate()
{
	/*if (AI == nullptr) return Failed;
	if (AI->GetMoveStatus() == EPathFollowingStatus::Moving) return Running;
	if (!AI->HasPartialPath()) return Failed;
	if (AI->GetPathFollowingComponent()->GetMoveGoal()->GetActorLocation() != TargetPosition)
	{
		AI->MoveToLocation(TargetPosition);
	}
	if (AI->)*/
	// if the distance to the endpos is smaller than the stopping distance return succes
	return Running;
}
