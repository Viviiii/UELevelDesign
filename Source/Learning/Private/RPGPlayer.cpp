// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGPlayer.h"
#include <Camera/CameraComponent.h>

// Sets default values
ARPGPlayer::ARPGPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	float speed = 20.f;
	float sensitivity = 15.f;
	//const FQuat rotationCam = 
	//Creation camera object
	//Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraTP"));
	//Camera-> AddLocalRotation()
	//FOllow the rotation of the object
	//Camera->bUsePawnControlRotation = true;
	//Attach it to component
	//Camera->SetupAttachment(GetMesh());
}

// Called when the game starts or when spawned
void ARPGPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARPGPlayer::MoveForward(float speed)
{
	const FVector direction = FRotationMatrix(FRotator(0.f, GetControlRotation().Yaw, 0.f)).GetUnitAxis(EAxis::X);
	AddMovementInput(direction, speed);
}

void ARPGPlayer::MoveRight(float speed)
{
	const FVector direction = FRotationMatrix(FRotator(0.f, GetControlRotation().Yaw, 0.f)).GetUnitAxis(EAxis::Y);
	AddMovementInput(direction, speed);
}

void ARPGPlayer::LookUp(float sensitivty)
{
	AddControllerPitchInput(sensitivty);
}

void ARPGPlayer::LookRight(float sensitivity)
{
	AddControllerYawInput(sensitivity);
}

// Called every frame
void ARPGPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARPGPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ARPGPlayer::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ARPGPlayer::MoveRight);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &ARPGPlayer::LookUp);
	PlayerInputComponent->BindAxis(FName("LookRight"), this, &ARPGPlayer::LookRight);

}

