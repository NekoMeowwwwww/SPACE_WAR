#pragma once
#include "Object.h"
class Enemy : public Object
{
public:
	Enemy();
	void Initalize();
	void Update();
	void Draw();
	Vector2f getPos()
	{
		Vector2f result;
		result.x = pos_.x;
		result.y = pos_.y;
		return result;
	}
	float getWidth()
	{
		return width;
	}
	float getHeight()
	{
		return height;
	}
	bool getIsAlive()
	{
		return isAlive_;
	}
	void setIsAlive(bool isAlive);
private:
	int respawnTimer;
};

