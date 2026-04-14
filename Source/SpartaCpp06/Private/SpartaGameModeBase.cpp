// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaCpp06/Public/SpartaGameModeBase.h"

ASpartaGameModeBase::ASpartaGameModeBase()
{
	SpawnCount = 3;
	SpawnInterval = 300.f;
	RandomYRange = 200.f;
	SpawnOrigin = FVector(0.0f, 0.0f, 0.0f);
}

void ASpartaGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	SpawnPlatforms();
}

void ASpartaGameModeBase::SpawnPlatforms()
{
	if (SpawnClasses.IsEmpty()) return;
	
	for (int32 i = 0; i < SpawnCount; ++i)
	{
		FVector SpawnLocation = SpawnOrigin;
		SpawnLocation.X += SpawnInterval * i;
		SpawnLocation.Y +=FMath::RandRange(-RandomYRange,RandomYRange);
		
		int32 RandomIndex = FMath::RandRange(0, SpawnClasses.Num() - 1);
		TSubclassOf<AActor> SelectedClass = SpawnClasses[RandomIndex];
		
		if (SelectedClass)
		{
			GetWorld()->SpawnActor<AActor>(
				SelectedClass,
				SpawnLocation,
				FRotator::ZeroRotator
				);
		}
	}
	
}
