#include "ThrowWeponGameMode.h"

AThrowWeponGameMode::AThrowWeponGameMode()
{
	// 4人分のスポーン位置を設定
	PlayerSpawnLocations[0] = FVector(-1500, -1500, 500);
	PlayerSpawnLocations[1] = FVector(1500, -1500, 500);
	PlayerSpawnLocations[2] = FVector(1500, 1500, 500);
	PlayerSpawnLocations[3] = FVector(-1500, 1500, 500);

	// 最初は0人
	PlayerCount = 0;

	Gametime = 180.0f;

	Countdown = 3;

	bCountdownActive = true;

	ElapsedTime = 0.0f;

	bGameStarted = false;
}

void AThrowWeponGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	// プレイヤーが参加したときの処理
	if (bCountdownActive)
	{
		GetWorldTimerManager().SetTimer(
			CountdownTimerHandle, this,
			&AThrowWeponGameMode::UpdateCountdown,
			1.0f, true
		);
	}
}

void AThrowWeponGameMode::RestartPlayer(AController* NewPlayer)
{
	if (PlayerCount >= 4) {
		return;
	}
	FTransform SpawnTransform;
	SpawnTransform.SetLocation(PlayerSpawnLocations[PlayerCount]);

	RestartPlayerAtTransform(NewPlayer, SpawnTransform);

	PlayerCount++;
}

void AThrowWeponGameMode::UpdateGameTime()
{
	ElapsedTime += 1.0f;

	if (ElapsedTime >= Gametime)
	{
		ElapsedTime = Gametime;

		// 3分経過
		GetWorldTimerManager().ClearTimer(GameTimerHandle);

		// ここにゲーム終了処理を入れる
	}
}

void AThrowWeponGameMode::UpdateCountdown()
{
	Countdown--;

	if (Countdown <= 0) {
		bCountdownActive = false;

		bGameStarted = true;

		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);

		GetWorldTimerManager().SetTimer(
			GameTimerHandle,
			this,
			&AThrowWeponGameMode::UpdateGameTime,
			1.0f,
			true
		);
	}
}
