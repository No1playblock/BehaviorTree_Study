// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "BossZDCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BEHAVIORTREE_STUDY_API ABossZDCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABossZDCharacter();

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent,
		AController* EventInstigator, AActor* DamageCauser) override;
	

	UPROPERTY(EditAnywhere, Category = Pawn)
	class UBehaviorTree* BehaviorTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Boss_Attack_Boolean = false;

private:
	UPROPERTY()
	float Boss_Health;
	
};
