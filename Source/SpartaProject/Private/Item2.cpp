// Fill out your copyright notice in the Description page of Project Settings.


#include "Item2.h"

// Sets default values
AItem2::AItem2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_AssetPlatform.SM_AssetPlatform"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	
	MoveSpeed = 200.0f;
	MaxRange = 500.0f;
	MoveDirection = 1.0f;


}

// Called when the game starts or when spawned
void AItem2::BeginPlay()
{
	Super::BeginPlay();

	
	
}

// Called every frame
void AItem2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	CurrentLocation.X += MoveSpeed * MoveDirection * DeltaTime;

	if (CurrentLocation.X >= StartLocation.X + MaxRange)
	{
		CurrentLocation.X = StartLocation.X + MaxRange;
		MoveDirection = -1.0f;
	}
	
	if (CurrentLocation.X <= StartLocation.X)
	{
		CurrentLocation.X = StartLocation.X;
		MoveDirection = 1.0f;
	}

	SetActorLocation(CurrentLocation);



}

