// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Behaviour.h"

/**
 * 
 */
class BEHAVIOURTREE_API Composite : public Behaviour
{
public:
	Composite(const TArray<Behaviour*>& Children) : Children(Children) {}
	~Composite();

	virtual void SetBlackBoard(::BlackBoard* BB) override
	{
		Behaviour::SetBlackBoard(BB);
		for (const auto child : Children)
		{
			child->SetBlackBoard(BB);
		}
	}

protected:
	typedef TArray<Behaviour*> Behaviours;
	Behaviours Children;
};
