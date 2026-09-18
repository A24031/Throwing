#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ThrowWeponGameMode.generated.h"

UCLASS()
class AThrowWeponGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	AThrowWeponGameMode();

protected:

	// プレイヤーがゲームに参加したときに呼ばれる
	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void RestartPlayer(AController* NewPlayer) override;
private:

	// 4人分のスポーン位置
	FVector PlayerSpawnLocations[4];

	// 現在何人のプレイヤーが参加しているか
	int32 PlayerCount;

	float
};