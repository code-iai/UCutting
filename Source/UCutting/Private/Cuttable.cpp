// Fill out your copyright notice in the Description page of Project Settings.


#include "Cuttable.h"
#include "Components/StaticMeshComponent.h" //StaticMeshComponent
#include "Engine/EngineTypes.h"

// Sets default values
ACuttable::ACuttable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
//    USceneComponent* RootSceneComponent= CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

    ProMesh=CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProMesh"));
    RootComponent=ProMesh;
//    ProMesh->SetupAttachment(RootComponent);
    //ProMesh->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform/*FAttachmentTransformRules::SnapToTargetIncludingScale*/);
    ProMesh->SetVisibility(true,true);
    ProMesh->SetSimulatePhysics(true);
    ProMesh->bUseComplexAsSimpleCollision=false;


    StaticMesh= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
//    static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Bush.SM_Bush'"))
    static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
    UStaticMesh* Asset = MeshAsset.Object;
    StaticMesh->SetStaticMesh(Asset);
//    StaticMesh->SetStaticMesh(Asset);
    StaticMesh->SetSimulatePhysics(true);
//    RootComponent=RootSceneComponent;
    StaticMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACuttable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACuttable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ACuttable::OnConstruction(const FTransform &Transform)
{
    Super::OnConstruction(Transform); //Call Parent first
    if(StaticMesh)
    {
        UKismetProceduralMeshLibrary::CopyProceduralMeshFromStaticMeshComponent(StaticMesh,0,ProMesh,true);
//        StaticMesh->AttachToComponent(RootComponent,FAttachmentTransformRules::SnapToTargetIncludingScale);

    }
}
