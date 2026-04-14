// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Star.generated.h"

UCLASS()
class SPARTACPP06_API AStar : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AStar();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
	USceneComponent* Root;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float FloatAmplitude;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float FloatSpeed;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float RotationSpeed;
	
private:
	float RunningTime;
	float InitalZ;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
