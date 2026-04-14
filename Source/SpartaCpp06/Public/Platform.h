// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Platform.generated.h"

UCLASS()
class SPARTACPP06_API APlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlatform();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	USceneComponent* Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float StartDelay;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float ToggleInterval;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	bool bIsActive;
	
	FTimerHandle ToggleTimerHandle;
	
	void TogglePlatform();
};
