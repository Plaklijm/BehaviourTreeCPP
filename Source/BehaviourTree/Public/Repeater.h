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
	~Repeater();

private:
	int InternalCount;
	int RepeatLimit;
	
protected:
	virtual void OnInitialize() override
	{
		InternalCount = 0;	
	}
	
	virtual Status OnUpdate() override
	{
		// make sure this loop runs when the amount is not equal to the internal counter
		while (true)
		{
			Child->tick();
			if (Child->GetStatus() == Running) break;
			if (Child->GetStatus() == Failed) return Failed;
			if (++InternalCount == RepeatLimit) return Success;
		}
	}
	
	virtual void OnTerminate(Status) override
	{
		// just to make sure the internal count is actually 0
		InternalCount = 0;	
	}
};
