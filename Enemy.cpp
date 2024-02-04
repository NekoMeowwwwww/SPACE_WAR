#include "Enemy.h"
#include <stdlib.h>
#include <time.h>
#include <Novice.h>
Enemy::Enemy()
{
	pos_ = { 1300.0f ,float(rand() % 657) };
	speed_ = { 10.0f,10.0f };
	width = 64.0f;
	height = 64.0f;
	isAlive_ = false;
	respawnTimer = 120 + rand() % 121;
}
void Enemy::Initalize()
{
	pos_ = { 1300.0f ,float(rand() % 657) };
	isAlive_ = false;
	respawnTimer = 120 + rand() % 121;
}
void Enemy::Update()
{
	if (!isAlive_)
	{
		if (respawnTimer > 0)
		{
			respawnTimer--;
		}
		else
		{
			Initalize();
			isAlive_ = true;
		}
	}
	else
	{
		pos_.x -= speed_.x;
		pos_.y += speed_.y;
		if (pos_.y <= 0 || pos_.y >= 656)
		{
			speed_.y *= -1;
		}
		if (pos_.x < -64.0f)
		{
			isAlive_ = false;
		}
	}
}
void Enemy::Draw()
{
	int Texture_Enemy = Novice::LoadTexture("./rs/emy.png");
	if (isAlive_)
	{
		Novice::DrawSprite((int)pos_.x, (int)pos_.y, Texture_Enemy, 1, 1, 0.0f, WHITE);
	}
}
void Enemy::setIsAlive(bool isAlive)
{
	this->isAlive_ = isAlive;
}