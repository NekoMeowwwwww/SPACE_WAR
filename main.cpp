#include <Novice.h>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"

const char kWindowTitle[] = "SPACE_WAR";

bool  IsSpriteCollision(float sprite1PosX, float sprite1Width, float sprite1PosY, float sprite1Height, float sprite2PosX, float sprite2Width, float sprite2PosY, float sprite2Height) {
	if (sprite1PosX <= sprite2PosX + sprite2Width && sprite2PosX <= sprite1PosX + sprite1Width && sprite1PosY <= sprite2PosY + sprite2Height && sprite2PosY <= sprite1PosY + sprite1Height) {
		return true;
	}
	else {
		return false;
	}
}
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	srand((unsigned)time(NULL));
	Player* player = new Player();
	Enemy* enemy[10];
	for (int i = 0; i < 10; i++)
	{
		enemy[i] = new Enemy();
	}
	Scene* scene = new Scene();
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		scene->Update(keys, preKeys, *player);
		if (scene->getSceneNum() == 0)
		{
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
			{
				player->Initalize();
				for (int i = 0; i < 10; i++)
				{
					enemy[i]->Initalize();
				}
			}
		}
		if (scene->getSceneNum() == 1)
		{
			player->Update(keys);
			for (int i = 0; i < 10; i++)
			{
				enemy[i]->Update();
			}
			for (int i = 0; i < 10; i++)
			{
				if (enemy[i]->getIsAlive() == true && player->getIsAlive() == true)
				{
					for (int j = 0; j < 10; j++)
					{
						if (player->bullet[j].isShot)
						{
							if (IsSpriteCollision(player->bullet[j].pos_.x, player->bullet[j].width, player->bullet[j].pos_.y, player->bullet[j].height, enemy[i]->getPos().x, enemy[i]->getWidth(), enemy[i]->getPos().y, enemy[i]->getHeight()))
							{
								enemy[i]->setIsAlive(false);
								player->bullet[j].isShot = false;
								player->setScore(player->getScore() + 1);
							}
						}
					}
					if (IsSpriteCollision(player->getPos().x, player->getWidth(), player->getPos().y, player->getHeight(), enemy[i]->getPos().x, enemy[i]->getWidth(), enemy[i]->getPos().y, enemy[i]->getHeight()))
					{
						player->setHp(player->getHp() - 10);
						enemy[i]->setIsAlive(false);
						if (player->getHp() <= 0)
						{
							player->setIsAlive(false);
						}
					}
				}
			}
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		scene->Draw();
		if (scene->getSceneNum() == 1)
		{
			player->Draw();
			for (int i = 0; i < 10; i++)
			{
				enemy[i]->Draw();
			}
			Novice::ScreenPrintf(600, 15, "score = %d", player->getScore());
			//hpbar
			if (player->getHp() >= 0) {
				Novice::DrawBox(440, 670, (int)(player->getHp() / player->getHpMax() * 400), 30, 0.0f, GREEN, kFillModeSolid);
			}

		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
