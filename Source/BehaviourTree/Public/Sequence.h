#pragma once
#include "Composite.h"

class Sequence : public Composite
{
protected:
	Behaviours::TConstIterator Current;

	virtual void OnInitialize() override
	{
		Current = Children.CreateConstIterator();
	}
	
	virtual Status OnUpdate() override
	{
		while (true)
		{
			Status s = (*Current)->tick();

			if (s != Success)
				return s;
			if (++Current == Children.end())
				return Success;
		}
		return Invalid;
	}
};
