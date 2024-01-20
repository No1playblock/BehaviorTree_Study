// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "PlayableZDCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BEHAVIORTREE_STUDY_API APlayableZDCharacter : public APaperZDCharacter
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);

	APlayableZDCharacter();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/* 실제 카메라 클래스 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/* CameraBoom 객체를 반환합니다. */
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/* FollowCamera 객체를 반환합니다. */
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }

};
