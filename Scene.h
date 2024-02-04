#pragma once
#include "Player.h"
class Scene
{
public:
	Scene();
	void Initalize();
	void Update(char* keys, char* preKeys, Player obj);
	void Draw();
	int getSceneNum()
	{
		return scene;
	}
private:
	typedef enum
	{
		Start,
		Game,
		Clear,
		End
	}SetScene;
	SetScene scene;
};