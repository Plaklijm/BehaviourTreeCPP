// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlackBoard.h"

/**
 * 
 */
enum Status { Invalid, Success, Running, Failed };
class BEHAVIOURTREE_API Behaviour
{
public:
	Behaviour() : EStatus(Invalid) {};
	virtual ~Behaviour() {}

	Status tick()
	{
		if (!OnEntered)
		{
			OnInitialize();
			OnEntered = true;
		}
		
		EStatus = OnUpdate();

		if (EStatus != Running)
		{
			OnTerminate(EStatus);
			OnEntered = false;
		}

		return EStatus;
	};

	virtual void SetBlackBoard(BlackBoard* BB)
	{
		BlackBoard = BB;
	}

	Status GetStatus() const
	{
		return EStatus;
	}
	
protected:
	virtual void OnInitialize() {};
	virtual Status OnUpdate() = 0;
	virtual void OnTerminate(Status) {};

	
	BlackBoard* BlackBoard;
	
private:
	Status EStatus;
	bool OnEntered {};
};
