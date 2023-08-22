// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LobbyGamemode.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSION_API ALobbyGamemode : public AGameModeBase
{
	GENERATED_BODY()
public:
	//跟踪玩家登入
	virtual void PostLogin(APlayerController* NewPlayer) override;
	//跟踪玩家登出
	virtual void Logout(AController* Exiting) override;
	
};
