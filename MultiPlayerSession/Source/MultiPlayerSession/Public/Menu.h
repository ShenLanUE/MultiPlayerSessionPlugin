// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Menu.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSION_API UMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="MultiPlayerSessions")
	void MenuSetup(int32 _NumPublicConnections = 4,FString _MatchTypeValue = FString(TEXT("FreeForAll"))
		,FString _PathToLobby = FString(TEXT("")));
	
protected:
	virtual bool Initialize() override;
	virtual void NativeDestruct() override;

	UFUNCTION()
	void OnCreateSession(bool bWasSuccessful);
	void OnFindSessions(const TArray<FOnlineSessionSearchResult>& SessionResults,bool bWaSuccess);
	void OnJoinSession(EOnJoinSessionCompleteResult::Type Result);
	
	UFUNCTION()
	void OnDestroySession(bool bWasSuccessful);
	
	UFUNCTION()
	void OnStartSession(bool bWasSuccessful);
	
private:

	UPROPERTY(meta=(BindWidget))
	class UButton* HostButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* JoinButton;

	UFUNCTION()
	void OnHostButtonClicked();
	
	UFUNCTION()
	void OnJoinButtonClicked();

	void MenuTearDown();

	UPROPERTY()
	class UMultiplayerSessionsSubsystem* MultiplayerSessionsSubsystem;

	int32 NumPublicConnections {4};
	FString MatchTypeValue {TEXT("FreeForAll")};
	FString PathToLobby{TEXT("")};
};
