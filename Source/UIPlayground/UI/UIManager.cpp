// Copyright © 2025 Damien He. All Rights Reserved.


#include "UIManager.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "UIPlayground/UIPlaygroundGameInstance.h"


void UUIManager::Initialize(const TObjectPtr<UUIPlaygroundGameInstance>& InGameInstance)
{
	CachedGameInstance = InGameInstance;
}

UUserWidget* UUIManager::ShowWidget(const TSubclassOf<UUserWidget> WidgetClass, EUILayerType Layer)
{
	if (!CachedGameInstance || !WidgetClass)
		return nullptr;

	UUserWidget* new_widget = CreateWidget<UUserWidget>(CachedGameInstance, WidgetClass);
	if (new_widget == nullptr)
		return nullptr;
	
	new_widget->AddToViewport();
	ActiveWidgets.FindOrAdd(Layer).Widgets.Add(new_widget);

	return new_widget;
}

void UUIManager::HideWidget(UUserWidget* Widget)
{
	if (!Widget)
		return;

	for (auto& widget_layer : ActiveWidgets)
	{
		// if more than one element as been removed from ActiveWidgets
		if (widget_layer.Value.Widgets.Remove(Widget) > 0)
		{
			Widget->RemoveFromParent();
		}
	}
}
