// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SpartaGameModeBase.generated.h"


UCLASS()
class SPARTACPP06_API ASpartaGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ASpartaGameModeBase();
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category = "Spawn")
	TArray<TSubclassOf<AActor>> SpawnClasses;
	UPROPERTY(EditAnywhere, Category = "Spawn")
	int32 SpawnCount;
	UPROPERTY(EditAnywhere, Category = "Spawn")
	float SpawnInterval;
	UPROPERTY(EditAnywhere, Category = "Spawn")
	float RandomYRange;
	UPROPERTY(EditAnywhere, Category = "Spawn")
	FVector SpawnOrigin;
	
	void SpawnPlatforms();
};
