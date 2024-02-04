#include "Player.h"
#include <Novice.h>
Player::Player()
{
	pos_ = { 50.0f,320.0f };
	speed_ = { 7.0f,7.0f };
	hpMax_ = 100.0f;;
	hp_ = hpMax_;
	width = 64.0f;
	height = 64.0f;
	isAlive_ = true;
	CD = 0;
	score_ = 0;
}
void Player::Initalize()
{
	pos_ = { 50.0f,320.0f };
	hpMax_ = 100.0f;;
	hp_ = hpMax_;
	isAlive_ = true;
	CD = 0;
	score_ = 0;
	for (int i = 0; i < 10; i++)
	{
		bullet[i].Initalize();
	}
}
void Player::Update(char* keys)
{
	if (keys[DIK_W]) {
		pos_.y -= speed_.y;
	}
	else if (keys[DIK_S]) {
		pos_.y += speed_.y;
	}
	else if (keys[DIK_A]) {
		pos_.x -= speed_.x;
	}
	else if (keys[DIK_D]) {
		pos_.x += speed_.x;
	}

	if (CD > 0)
	{
		CD--;
	}
	else
	{
		CD = 15;
	}
	if (CD <= 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (keys[DIK_J]) {
				if (!bullet[i].isShot) {
					bullet[i].pos_.x = pos_.x;
					bullet[i].pos_.y = pos_.y;
					bullet[i].isShot = true;
					break;
				}
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		bullet[i].Update();
	}
}
void Player::Draw()
{
	int Texture_Player = Novice::LoadTexture("./rs/plr.png");
	for (int i = 0; i < 10; i++)
	{
		bullet[i].Draw();
	}
	if (isAlive_)
	{
		Novice::DrawSprite((int)pos_.x, (int)pos_.y, Texture_Player, 1, 1, 0.0f, WHITE);
	}
}
void Player::setHp(float hp)
{
	this->hp_ = hp;
}
void Player::setIsAlive(bool isAlive)
{
	this->isAlive_ = isAlive;
}
void Player::setScore(int score)
{
	this->score_ = score;
}