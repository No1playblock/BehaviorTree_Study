// Fill out your copyright notice in the Description page of Project Settings.


#include "BossZDCharacter.h"
#include "GameFramework/PawnMovementComponent.h"

ABossZDCharacter::ABossZDCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Boss_Health = 100.0f;

	GetMovementComponent()->NavAgentProps.AgentHeight = 320.0f;
	GetMovementComponent()->NavAgentProps.AgentRadius = 160.0f;
	//Boss_Attack_Boolean = false;

}

float ABossZDCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent,
	AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	Boss_Health -= Damage;
	return Damage;
}

