#include "Bullet.h"
#include <Novice.h>
Bullet::Bullet() {
	pos_.x = -100.0f;
	pos_.y = -100.0f;
	isShot = false;
	width = 32.0f;
	height = 32.0f;
	speed_ = { 30.0f,30.0f };
}
void Bullet::Initalize()
{
	pos_.x = -100.0f;
	pos_.y = -100.0f;
	isShot = false;
}
void Bullet::Update() {
	if (isShot) {
		pos_.x += speed_.x;
		if (pos_.x > 1280) {
			Initalize();
		}
	}
}

void Bullet::Draw() {
	if (isShot)
	{
		int Texture_Bullet = Novice::LoadTexture("./rs/blt.png");
		Novice::DrawSprite((int)pos_.x, (int)pos_.y + 16, Texture_Bullet, 1, 1, 0.0f, WHITE);
	}
}