// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HttpModule.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Delegates/DelegateCombinations.h"
#include "Delegates/DelegateCombinations.h"
#include "CommunicationWidgetBase.generated.h"

USTRUCT(BlueprintType)
struct FBravoUser
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int32 BravoId;
	UPROPERTY(BlueprintReadWrite)
	FString BravoGender;
	UPROPERTY(BlueprintReadWrite)
	FDateTime BravoBirthday;
	UPROPERTY(BlueprintReadWrite)
	FString BravoName;
	UPROPERTY(BlueprintReadWrite)
	int BravoAge;
	UPROPERTY(BlueprintReadWrite)
	FString AccountId;
	UPROPERTY(BlueprintReadWrite)
	FString Password;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnConnectToSpringBootSucceed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnConnectToSpringBootFailed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSignUpSucceed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSignUpFailed);
/**
 * 基本的http通信类
 */
UCLASS()
class CHANNELCHATVIEW_API UCommunicationWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "SpringBoot")
	void ConnectToSpringBoot();

	UFUNCTION(BlueprintCallable, Category = "SpringBoot")
	void RegisterBravoUser(FBravoUser User);

	UPROPERTY(BlueprintAssignable, Category = "SpringBoot")
	FOnSignUpSucceed SignUpSucceed;

	UPROPERTY(BlueprintAssignable, Category = "SpringBoot")
	FOnSignUpFailed SignUpFailed;

	UPROPERTY(BlueprintAssignable, Category = "SpringBoot")
	FOnConnectToSpringBootSucceed ConnectToSpringBootSucceed;

	UPROPERTY(BlueprintAssignable, Category = "SpringBoot")
	FOnConnectToSpringBootFailed ConnectToSpringBootFailed;

private:
	static FString BravoUserToString(FBravoUser User);
	
	static FString BravoUserToJson(FBravoUser User);

	void HandleSpringBootResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	void HandleRegisterBravoUser(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};
