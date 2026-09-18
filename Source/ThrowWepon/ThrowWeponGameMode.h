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
	//制限時間
	float Gametime;
	//ゲーム開始からの経過時間
	float ElapsedTime;
	//ゲームが開始したか
	bool bGameStarted;
	//タイマー処理
	FTimerHandle GameTimerHandle;
	//ゲーム時間を更新する関数
	void UpdateGameTime();

    //カウントダウンの現在値
	int32 Countdown;

	//カウントダウン中か
	bool bCountdownActive;

	//カウントダウン用タイマー
	FTimerHandle CountdownTimerHandle;

	//カウントダウン処理
	void UpdateCountdown();
};