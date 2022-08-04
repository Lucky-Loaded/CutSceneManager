// Copyright (c) 2020 - 2022 GameWheelStudio. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PZ_CutSceneComponent.generated.h"




class ULevelSequencePlayer;



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCutSceneStarted, ULevelSequencePlayer*, LevelSequence);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCutScenePaused);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCutSceneEnded);



/*
	Component for managing Cut-Scenes
*/
UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PZ_CUTSCENEMANAGER_API UPZ_CutSceneComponent : public UActorComponent
{
	GENERATED_BODY()
		
//constructor
public:

	UPZ_CutSceneComponent();




//c++ public methods
public:

	//UActorComponent
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type Reason) override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	//~UActorComponent




//c++ private values
private:

	/*
		Cut-Scene that is active now.
	*/
	UPROPERTY()
		ULevelSequencePlayer* CurrentCutScene = nullptr;



//>>..............................................................................................................<<//


//Blueprint methods
public:

	UFUNCTION(BlueprintCallable, Category = "CutSceneComponent")
		void StartCutScene(ULevelSequencePlayer* CutScene);
	UPROPERTY(BlueprintAssignable, Category = "CutSceneComponent|EventsForBind")
		FOnCutSceneStarted OnCutSceneStartedBind;

	UFUNCTION(BlueprintCallable, Category = "CutSceneComponent")
		void PauseCutScene();
	UPROPERTY(BlueprintAssignable, Category = "CutSceneComponent|EventsForBind")
		FOnCutScenePaused OnCutScenePausedBind;

	UFUNCTION(BlueprintCallable, Category = "CutSceneComponent")
		void EndCutScene();
	UPROPERTY(BlueprintAssignable, Category = "CutSceneComponent|EventsForBind")
		FOnCutSceneEnded OnCutSceneEndedBind;

	UFUNCTION(BlueprintCallable, Category = "CutSceneComponent")
		void StopCutSceneAtCurrentTime();

	UFUNCTION(BlueprintCallable, Category = "CutSceneComponent")
		void RestartCurrentCutScene();



	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "CutSceneComponent")
		ULevelSequencePlayer* GetCurrentCutScene() const { return CurrentCutScene; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "CutSceneComponent")
		bool IsCutScenePlaying() const;
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "CutSceneComponent")
		bool IsCutScenePaused() const;

	UFUNCTION(BlueprintCallable, Category = "CutSceneComponent")
		void SetCutScenePlayRate(float PlayRate);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "CutSceneComponent")
		float GetCutScenePlayRate() const;


//Blueprint values
public:


};