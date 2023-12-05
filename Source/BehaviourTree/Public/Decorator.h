// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Behaviour.h"

/**
 * 
 */
class BEHAVIOURTREE_API Decorator : public Behaviour
{
public:
	Decorator(Behaviour* child) : Child(child) {}
	~Decorator();

	virtual void SetBlackBoard(::BlackBoard* BB) override
	{
		Behaviour::SetBlackBoard(BB);
		Child->SetBlackBoard(BB);
	}

protected:
	Behaviour* Child;


};
