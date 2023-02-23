// Fill out your copyright notice in the Description page of Project Settings.

#include "http.h"
#include "../Public/CommunicationWidgetBase.h"

void UCommunicationWidgetBase::ConnectToSpringBoot()
{
	const FString ConnectUrl = TEXT("http://localhost:8080/Unreal");
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> ChannelBravoRequest = FHttpModule::Get().CreateRequest();
	ChannelBravoRequest->SetURL(ConnectUrl);
	ChannelBravoRequest->SetVerb(TEXT("GET"));
	// Request->SetHeader(TEXT("Accept"), TEXT("*/*")); // 添加Accept头

	ChannelBravoRequest->OnProcessRequestComplete().BindUObject(this, &UCommunicationWidgetBase::HandleSpringBootResponse);
	ChannelBravoRequest->ProcessRequest();
}

void UCommunicationWidgetBase::HandleSpringBootResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	int32 ResponseCode = Response->GetResponseCode();
	if (bWasSuccessful && Response.IsValid() && ResponseCode == EHttpResponseCodes::Ok)
	{
		ConnectToSpringBootSucceed.Broadcast();
	}
	else
	{
		ConnectToSpringBootFailed.Broadcast();
		UE_LOG(LogTemp, Error, TEXT("Failed to connect to SpringBoot service"));
	}
}

void UCommunicationWidgetBase::HandleRegisterBravoUser(FHttpRequestPtr Request, FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	int32 ResponseCode = Response->GetResponseCode();
	if (bWasSuccessful && Response.IsValid() && ResponseCode == EHttpResponseCodes::Ok)
	{
		SignUpSucceed.Broadcast();
	}
	else
	{
		SignUpFailed.Broadcast();
	}
}

void UCommunicationWidgetBase::RegisterBravoUser(FBravoUser const User)
{
	const FString SignUpUrl = TEXT("http://localhost:8080/Register/SignUp");

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> ChannelBravoRequest = FHttpModule::Get().CreateRequest();
	ChannelBravoRequest->SetURL(SignUpUrl);
	ChannelBravoRequest->SetVerb(TEXT("POST"));
	ChannelBravoRequest->SetHeader(TEXT("Content-Type"),TEXT("application/x-www-form-urlencoded"));
	ChannelBravoRequest->SetContentAsString(BravoUserToString(User));

	ChannelBravoRequest->OnProcessRequestComplete().BindUObject(this, &UCommunicationWidgetBase::HandleRegisterBravoUser);
	ChannelBravoRequest->ProcessRequest();
}

FString UCommunicationWidgetBase::BravoUserToString(FBravoUser const User)
{
	FString Content = FString::Printf(TEXT("bravoGender=%s&bravoBirthday=%s&bravoName=%s&bravoAge=%d&accountId=%s&password=%s"),
		*User.BravoGender,*User.BravoBirthday.ToString(TEXT("%Y-%m-%d")),*User.BravoName,User.BravoAge,*User.AccountId,*User.Password);
	return Content;
}

FString UCommunicationWidgetBase::BravoUserToJson(FBravoUser const User)
{
	const TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField("bravoGender",*User.BravoGender);
	JsonObject->SetStringField("bravoBirthday",*User.BravoBirthday.ToString(TEXT("%Y-%m-%d")));
	JsonObject->SetStringField("bravoName",*User.BravoName);
	JsonObject->SetNumberField("bravoAge",User.BravoAge);
	JsonObject->SetStringField("accountId",*User.AccountId);
	JsonObject->SetStringField("password",*User.Password);
	FString ResultString = "";
	const TSharedRef<TJsonWriter<>> JsonWriter = TJsonWriterFactory<>::Create(&ResultString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);
	return ResultString;
}
