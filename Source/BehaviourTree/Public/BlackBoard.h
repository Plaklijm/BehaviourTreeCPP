// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/UnrealTypePrivate.h"

/**
 * 
 */
class BEHAVIOURTREE_API BlackBoard
{
public:
	BlackBoard();
	~BlackBoard();

	template <typename T>
	T GetValue(FString key)
	{
		if (Data.Contains(key))
			return Data[key];

		return T();
	}
	
	void SetValue(FString key, const float& variable)
	{
		if (Data.Contains(key))
		{
			Data[key] = variable;
		}
		else
			Data.Add(key, variable);
	}
	
private:
	TMap<FString, float> Data;
	
};
