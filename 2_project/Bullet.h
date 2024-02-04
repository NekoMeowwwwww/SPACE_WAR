#pragma once
#include "Struct.h"
class Bullet
{
public:
	Vector2f pos_;
	Vector2f speed_;
	float width;
	float height;
	bool isShot;
	Bullet();
	void Initalize();
	void Update();
	void Draw();
};