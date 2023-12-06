// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Decorator.h"

/**
 * 
 */
class BEHAVIOURTREE_API Repeater : public Decorator
{
public:
	Repeater(int Amount, Behaviour* Child) : Decorator(Child), RepeatLimit(Amount) { InternalCount = {}; }

private:
	int InternalCount;
	int RepeatLimit;
	
protected:
	virtual void OnInitialize() override
	{
		InternalCount = 0;
		UE_LOG(LogTemp, Error, TEXT("INIT, LIMIT = %i"), RepeatLimit);
	}
	
	virtual Status OnUpdate() override
	{
		UE_LOG(LogTemp, Warning, TEXT("%i"), InternalCount);
		if(Child->tick() == Running)
		{
			InternalCount++;
		}
		if (InternalCount >= RepeatLimit)
		{
			return Success;
		}
		return Running;
	}
	
	virtual void OnTerminate(Status) override
	{
		// just to make sure the internal count is actually 0
		UE_LOG(LogTemp, Error, TEXT("TERMINATE"));
		InternalCount = 0;	
	}
};
