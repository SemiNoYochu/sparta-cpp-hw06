// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaCpp06/Public/Pillar.h"


// Sets default values
APillar::APillar()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	Root = CreateDefaultSubobject<USceneComponent>("Scene");
	SetRootComponent(Root);
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(Root);
	
	bIsActive = true;
	ToggleInterval = 2.0f;
}

// Called when the game starts or when spawned
void APillar::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(
		ToggleTimerHandle,
		this,
		&APillar::TogglePlatform,
		ToggleInterval,
		true,
		StartDelay
		);
	
}

void APillar::TogglePlatform()
{
	bIsActive = !bIsActive;
	
	SetActorHiddenInGame(bIsActive);
	SetActorEnableCollision(bIsActive); 
}


