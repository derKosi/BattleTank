// Copyright Mathias Kosinski 2018

#include "../Public/TankAIController.h"

// Sets default values
ATankAIController::ATankAIController()
{
	// Set this player controller to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	//auto ControlledTank = GetControlledTank();
	//if (!ControlledTank)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"));
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("AIayerController possessing: %s"), *(ControlledTank->GetName()));
	//}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
	}
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
