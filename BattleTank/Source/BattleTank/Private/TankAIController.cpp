// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank!"));
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController attached to %s"), *ControlledTank->GetName());
	}

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not get Player Tank!"));
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Got Player Tank: %s"), *PlayerTank->GetName());
	}



}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if(!PlayerPawn)
	{ 
		return nullptr;
	}
	else
	{
		return Cast<ATank>(PlayerPawn);
	}
}
