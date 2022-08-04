// Copyright (c) 2020 - 2022 GameWheelStudio. All rights reserved.

#include "CutSceneComponent/PZ_CutSceneComponent.h"

#include "LevelSequencePlayer.h"
#include "MovieSceneSequencePlayer.h"





UPZ_CutSceneComponent::UPZ_CutSceneComponent()
{
}




void UPZ_CutSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	//TODO on child
}

void UPZ_CutSceneComponent::EndPlay(const EEndPlayReason::Type Reason)
{
	Super::EndPlay(Reason);

	//TODO on child
}

void UPZ_CutSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//TODO on child
}






void UPZ_CutSceneComponent::StartCutScene(ULevelSequencePlayer* CutScene)
{
	if( !IsValid(CutScene) ) return;

	EndCutScene(); //if we have active cut-scene
	CurrentCutScene = CutScene;
	CurrentCutScene->Play();

	OnCutSceneStartedBind.Broadcast(CurrentCutScene);
}

void UPZ_CutSceneComponent::PauseCutScene()
{
	if( !IsValid(CurrentCutScene) ) return;

	CurrentCutScene->Pause();
	OnCutScenePausedBind.Broadcast();
}

void UPZ_CutSceneComponent::EndCutScene()
{
	if( !IsValid(CurrentCutScene) ) return;

	CurrentCutScene->Stop();
	OnCutSceneEndedBind.Broadcast();

	CurrentCutScene = nullptr;
}

void UPZ_CutSceneComponent::StopCutSceneAtCurrentTime()
{
	if( !IsValid(CurrentCutScene) ) return;

	CurrentCutScene->StopAtCurrentTime();
}

void UPZ_CutSceneComponent::RestartCurrentCutScene()
{
	if( !IsValid(CurrentCutScene) ) return;

	CurrentCutScene->Stop();
	CurrentCutScene->Play();
}






bool UPZ_CutSceneComponent::IsCutScenePlaying() const
{
	return (IsValid(CurrentCutScene)) ? CurrentCutScene->IsPlaying() : false;
}

bool UPZ_CutSceneComponent::IsCutScenePaused() const
{
	return (IsValid(CurrentCutScene)) ? CurrentCutScene->IsPaused() : false;
}

void UPZ_CutSceneComponent::SetCutScenePlayRate(float PlayRate)
{
	if( !IsValid(CurrentCutScene) ) return;

	CurrentCutScene->SetPlayRate(PlayRate);
}

float UPZ_CutSceneComponent::GetCutScenePlayRate() const
{
	return (IsValid(CurrentCutScene)) ? CurrentCutScene->GetPlayRate() : 0.0f;
}
