// Copyright © 2025 Damien He. All Rights Reserved.


#include "UIPlaygroundGameInstance.h"
#include "UI//UIManager.h"



void UUIPlaygroundGameInstance::Init()
{
	Super::Init();

	// Create and initialize UI Manager
	CachedUIManager = NewObject<UUIManager>();
	CachedUIManager->Initialize(this);
}