// Copyright © 2025 Damien He. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIManager.generated.h"

class UUIPlaygroundGameInstance;

UENUM(BlueprintType)
enum class EUILayerType : uint8
{
	Persistent UMETA(DisplayName = "Persistent"),
	Contextual UMETA(DisplayName = "Contextual"),
	Popup UMETA(DisplayName = "Popup"),
	Fullscreen UMETA(DisplayName = "Fullscreen"),
	Diegetic UMETA(DisplayName = "Diegetic"),
	Debug UMETA(DisplayName = "Debug")
};

USTRUCT(BlueprintType)
struct FUIWidgetLayer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<UUserWidget>> Widgets;
};

/**
 * 
 */
UCLASS()
class UIPLAYGROUND_API UUIManager : public UObject
{
	GENERATED_BODY()

	
public:
	void Initialize(const TObjectPtr<UUIPlaygroundGameInstance>& InGameInstance);

	UFUNCTION(BlueprintCallable)
	UUserWidget* ShowWidget(const TSubclassOf<UUserWidget> WidgetClass, EUILayerType Layer);
	UFUNCTION(BlueprintCallable)
	void HideWidget(UUserWidget* Widget);

private:
	UPROPERTY()
	TObjectPtr<UUIPlaygroundGameInstance> CachedGameInstance;

	UPROPERTY()
	TMap<EUILayerType, FUIWidgetLayer> ActiveWidgets;
};
