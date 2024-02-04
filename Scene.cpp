#include "Scene.h"
#include <Novice.h>
Scene::Scene()
{
	scene = Start;
}
void Scene::Initalize()
{
	scene = Start;
}
void Scene::Update(char* keys, char* preKeys, Player obj)
{
	switch (scene)
	{
	case Start:
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
		{
			scene = Game;
		}
		break;
	case Game:
		if (obj.getHp() <= 0)
		{
			scene = End;
		}
		if (obj.getScore() >= 20)
		{
			scene = Clear;
		}
		break;
	case Clear:
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
		{
			Initalize();
		}
		break;
	case End:
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
		{
			Initalize();
		}
		break;
	}
}
void Scene::Draw()
{
	int Texture_Title = Novice::LoadTexture("./rs/bg2.png");
	int Texture_BG = Novice::LoadTexture("./rs/bg1.png");
	int Texture_Win = Novice::LoadTexture("./rs/bg3.png");
	int Texture_Lose = Novice::LoadTexture("./rs/bg4.png");
	switch (scene)
	{
	case Start:
		Novice::DrawSprite(0, 0, Texture_Title, 1, 1, 0.0f, WHITE);
		break;
	case Game:
		Novice::DrawSprite(0, 0, Texture_BG, 1, 1, 0.0f, WHITE);
		break;
	case Clear:
		Novice::DrawSprite(0, 0, Texture_Win, 1, 1, 0.0f, WHITE);
		break;
	case End:
		Novice::DrawSprite(0, 0, Texture_Lose, 1, 1, 0.0f, WHITE);
		break;
	}
}