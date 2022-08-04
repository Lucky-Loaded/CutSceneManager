// Copyright (c) 2020 - 2022 GameWheelStudio. All rights reserved.

#include "PZ_CutSceneManager.h"





#define LOCTEXT_NAMESPACE "FPZ_CutSceneManagerModule"


void FPZ_CutSceneManagerModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FPZ_CutSceneManagerModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPZ_CutSceneManagerModule, PZ_CutSceneManager)