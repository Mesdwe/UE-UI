// Copyright © 2025 Damien He. All Rights Reserved.


#include "UIPlaygroundHelperLibrary.h"

UUIPlaygroundGameInstance* UUIPlaygroundHelperLibrary::GetUIPlaygroundGameInstance(UObject* WorldContextObject)
{
	if (!WorldContextObject) return nullptr;
	return Cast<UUIPlaygroundGameInstance>(WorldContextObject->GetWorld()->GetGameInstance());
}

UUIManager* UUIPlaygroundHelperLibrary::GetUIManager(UObject* WorldContextObject)
{
	UUIPlaygroundGameInstance* game_instance = GetUIPlaygroundGameInstance(WorldContextObject);
	return game_instance ? game_instance->GetUIManager() : nullptr;
}
