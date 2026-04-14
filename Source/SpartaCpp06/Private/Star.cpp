// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaCpp06/Public/Star.h"


// Sets default values
AStar::AStar()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(Root);
	
	FloatAmplitude = 100.0f;
	FloatSpeed = 1.0f;
	RotationSpeed = 90.0f;
}

// Called when the game starts or when spawned
void AStar::BeginPlay()
{
	Super::BeginPlay();
	InitalZ = GetActorLocation().Z;
}

// Called every frame
void AStar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	RunningTime += DeltaTime;
	
	float NewZ = InitalZ + FMath::Sin(RunningTime * FloatSpeed) * FloatAmplitude;
	SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, NewZ));
	
	
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
	
}

