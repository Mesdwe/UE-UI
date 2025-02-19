// Copyright © 2025 Damien He. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UIPlaygroundGameInstance.generated.h"

class UUIManager;
/**
 * 
 */
UCLASS()
class UIPLAYGROUND_API UUIPlaygroundGameInstance : public UGameInstance
{
	GENERATED_BODY()

	
public:
	virtual void Init() override;

	// Get UI Manager
	UFUNCTION(BlueprintCallable)
	UUIManager* GetUIManager() const { return CachedUIManager; }

protected:
	UPROPERTY()
	UUIManager* CachedUIManager;
};
