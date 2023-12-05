// Fill out your copyright notice in the Description page of Project Settings.


#include "Patrol.h"


Patrol::Patrol(const float MoveSpeed, FString TargetPosKey)
{
	this->MoveSpeed = MoveSpeed;
	this->TargetPosKey = TargetPosKey;
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
	// if there isnt a agent return failed
	// if the agent is still walking to the path return running
	// if the agent has a path && that path is invalid return failed
	// if the agent endpos != targetpos set destination to targetpos
	// if the distance to the endpos is smaller than the stopping distance return succes
	return Running;
}
