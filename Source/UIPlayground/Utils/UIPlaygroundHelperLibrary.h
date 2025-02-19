// Copyright © 2025 Damien He. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UIPlayground/UIPlaygroundGameInstance.h"
#include "UIPlaygroundHelperLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UIPLAYGROUND_API UUIPlaygroundHelperLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "UIPlaygroundHelperLibrary", meta = (WorldContext = "WorldContextObject"))
	static UUIPlaygroundGameInstance* GetUIPlaygroundGameInstance(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category = "UIPlaygroundHelperLibrary", meta = (WorldContext = "WorldContextObject"))
	static UUIManager* GetUIManager(UObject* WorldContextObject);
};
