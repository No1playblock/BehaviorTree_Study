// Fill out your copyright notice in the Description page of Project Settings.


#include "Boss_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BossZDCharacter.h"

ABoss_AIController::ABoss_AIController()
{
	UE_LOG(LogTemp, Log, TEXT("constructor"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
	check(BlackboardComp);

	BehaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComp"));
	check(BehaviorTreeComp);

}


void ABoss_AIController::OnPossess(APawn* InPawn)		//pawn's name : FPBossCharacter
{
	Super::OnPossess(InPawn);

	ABossZDCharacter* possessedPawn = Cast<ABossZDCharacter>(InPawn);

	if (InPawn != nullptr)
	{
		BlackboardComp->InitializeBlackboard(*(possessedPawn->BehaviorTree->BlackboardAsset));
		BehaviorTreeComp->StartTree(*(possessedPawn->BehaviorTree));
		GetBlackboard()->SetValueAsVector(TEXT("HomeLocation"), InPawn->GetActorLocation());
		GetBlackboard()->SetValueAsObject(TEXT("AICharacter"), possessedPawn);
	}

}
UBlackboardComponent* ABoss_AIController::GetBlackboard()
{
	return BlackboardComp;
}