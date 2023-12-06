// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Behaviour.h"

/**
 * 
 */
class BEHAVIOURTREE_API TestBehaviour : public Behaviour
{
public:
	TestBehaviour(FString Log) : String(Log) {}

	virtual Status OnUpdate() override
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *String);
		return Running;
	}

	private:
	FString String;
};
