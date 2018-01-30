// Copyright Mathias Kosinski 2018

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/World.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
		
public:
	// Sets default values for this pawn's properties
	ATankAIController();

private:
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};