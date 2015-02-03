// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once 

#include "Runtime/Engine/Classes/Engine/Console.h"
#include "UTConsole.generated.h"

UCLASS()
class UUTConsole : public UConsole
{
	GENERATED_UCLASS_BODY()

	virtual void FakeGotoState(FName NextStateName);

private:
	bool bReopenMenus;

};

