// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Agent.h"
#include "CoreMinimal.h"
#include "Food.h"
#include "GameFramework/Actor.h"
#include "GridNode.h"
#include "LevelGenerator.generated.h"

UCLASS()
class FIT3094_A1_CODE_API ALevelGenerator : public AActor
{
	GENERATED_BODY()

	// Maximum Size for World Map
	static const int MAX_MAP_SIZE = 255;

public:

	// Grid Size in World Units
	static const int GRID_SIZE_WORLD = 100;
	static const int NUM_FOOD = 25;
	static const int NUM_AGENTS = 5;
	
	// Sets default values for this actor's properties
	ALevelGenerator();

	UPROPERTY(BlueprintReadOnly)
		int MapSizeX;
	UPROPERTY(BlueprintReadOnly)
		int MapSizeY;
	
	// This is a 2D Array for holding all the elements of the world loaded from file
	//char CharMapArray[MAX_MAP_SIZE][MAX_MAP_SIZE];

	// This is a 2D Array for holding nodes for each part of the world
	GridNode* WorldArray[MAX_MAP_SIZE][MAX_MAP_SIZE];

	UPROPERTY()
		TArray<AFood*> FoodActors;

	// Actors for spawning into the world
	UPROPERTY(EditAnywhere, Category = "Entities")
		TSubclassOf<AActor> WallBlueprint;
	UPROPERTY(EditAnywhere, Category = "Entities")
		TSubclassOf<AActor> OpenBlueprint;
	UPROPERTY(EditAnywhere, Category = "Entities")
		TSubclassOf<AActor> TreeBlueprint;
	UPROPERTY(EditAnywhere, Category = "Entities")
		TSubclassOf<AActor> SwampBlueprint;
	UPROPERTY(EditAnywhere, Category = "Entities")
		TSubclassOf<AActor> WaterBlueprint;
	UPROPERTY(EditAnywhere, Category = "Entities")
		TSubclassOf<AActor> FoodBlueprint;
	UPROPERTY(EditAnywhere, Category = "Entities")
		TSubclassOf<AActor> AgentBlueprint;
	UPROPERTY(EditAnywhere, Category = "Entities")
		AActor* Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SpawnWorldActors(char Grid[MAX_MAP_SIZE][MAX_MAP_SIZE]);

	void GenerateNodeGrid(char Grid[MAX_MAP_SIZE][MAX_MAP_SIZE]);
	void ResetAllNodes();

	float CalculateDistanceBetween(GridNode* first, GridNode* second);

	// Handle for Timer
	FTimerHandle FoodTimerHandle;

	void SpawnFood();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void GenerateWorldFromFile(TArray<FString> WorldArray);

};
