// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Logging/LogMacros.h"
#include "SilenceCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class USpringArmComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ASilenceCharacter : public ACharacter
{
	GENERATED_BODY()

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Value, meta=(AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* UseAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* SprintAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* WalkAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputAction* CancelAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Value, meta=(AllowPrivateAccess = "true"))
	bool bCanMove = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Value, meta=(AllowPrivateAccess = "true"))
	bool bCanLook = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Value, meta=(AllowPrivateAccess = "true"))
	bool bCanJump = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Value, meta=(AllowPrivateAccess = "true"))
	float MouseX = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Value, meta=(AllowPrivateAccess = "true"))
	float MouseY = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Value, meta=(AllowPrivateAccess = "true"))
	float MovementLeftRight = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Value, meta=(AllowPrivateAccess = "true"))
	float MovementForwardBackward = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Value, meta=(AllowPrivateAccess = "true"))
	bool bIsUsingLightActor = true;
	
public:
	ASilenceCharacter();

protected:
	virtual void BeginPlay();

public:
		
	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

protected:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void CustomJump(const FInputActionValue& Value);


protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

public:
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

};

