// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Behaviour.h"
#include "Composite.h"

/**
 * 
 */
class BEHAVIOURTREE_API Selector : public Composite
{
public:
	Selector();
	~Selector();

protected:
	Behaviours::TConstIterator Current;

	virtual void OnInitialize() override
	{
		Current = Children.CreateConstIterator().GetIndex();
	}
	
	virtual Status OnUpdate() override
	{
		while (true)
		{
			const Status s = (*Current)->tick();

			if (s != Failed)
				return s;
			// TODO: Find another way to check if the end is reached
			if (++Current == Children.end())
				return Failed;
		}
		return Invalid;
	}
};
