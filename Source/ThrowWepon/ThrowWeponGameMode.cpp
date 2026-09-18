#include "ThrowWeponGameMode.h"

AThrowWeponGameMode::AThrowWeponGameMode()
{
	// 4人分のスポーン位置を設定
	PlayerSpawnLocations[0] = FVector(0, 0, 100);
	PlayerSpawnLocations[1] = FVector(500, 0, 100);
	PlayerSpawnLocations[2] = FVector(0, 500, 100);
	PlayerSpawnLocations[3] = FVector(500, 500, 100);

	// 最初は0人
	PlayerCount = 0;
}

void AThrowWeponGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	// プレイヤーが参加したときの処理
}

/*void AThrowWeponGameMode::RestartPlayer(AController* NewPlayer)
{
	if (PlayerCount >= 4) {
		return;
	}
	FTransform SpawnTransform;
	SpawnTransform.SetLocation(PlayerSpawnLocations[PlayerCount]);

	RestartPlayerAtTransform(NewPlayer, SpawnTransform);

	PlayerCount++;
}*/
