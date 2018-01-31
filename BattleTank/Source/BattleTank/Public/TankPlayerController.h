// Copyright Mathias Kosinski 2018

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATankPlayerController();

private:
	ATank* GetControlledTank() const;

	// Start the tank moving the barrel so that a shot
	// would hit where the crosshair intersects the world
	void AimTowardsCrosshair();
	
	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = .5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = .33333;

};
