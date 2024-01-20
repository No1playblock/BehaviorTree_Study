// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Boss_AIController.generated.h"

/**
 * 
 */
UCLASS()
class BEHAVIORTREE_STUDY_API ABoss_AIController : public AAIController
{
	GENERATED_BODY()

	ABoss_AIController();
	virtual void OnPossess(APawn* InPawn) override;

	UBlackboardComponent* GetBlackboard();

protected:
	UPROPERTY(BlueprintReadWrite, Category = Behavor)
	class UBlackboardComponent* BlackboardComp;

	UPROPERTY(BlueprintReadWrite, Category = Behavior)
	class UBehaviorTreeComponent* BehaviorTreeComp;
	
};
