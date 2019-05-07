#include "Bullet.h"



Bullet::Bullet(exEngineInterface * mEngine, float startX, float startY, float destX, float destY)
{

	mSizeX = 1;
	mSizeY = 20;

	posX = startX;
	posY = startY;

	startPosX = startX;
	startPosY = startY;

	this->mEngine = mEngine;

	if (destX == -1 && destY == -1)
	{
		int mouseX;
		int mouseY;

		SDL_GetMouseState(&mouseX, &mouseY);
		CalculateXYDirection(startX, startY, mouseX, mouseY);
	}
	else
	{
		CalculateXYDirection(startX, startY, destX, destY);
	}
}

Bullet::~Bullet()
{
}

void Bullet::CalculateXYDirection(float startX, float startY, float destX, float destY)
{
	float destination = sqrt(pow((destX - startX), 2) + pow((destY - startY), 2));
	directionX = (destX - startX) / destination;
	directionY = (destY - startY) / destination;
}

void Bullet::ShootMissile(float time, float speed, exColor color)
{
	posX += directionX * time * speed;
	posY += directionY * time * speed;

	DrawBullet(color);
}

void Bullet::DrawBullet(exColor color)
{
	p1.x = startPosX + mSizeX / 2;
	p2.x = posX;

	p1.y = startPosY + mSizeY / 2;
	p2.y = posY;

	mEngine->DrawLine(p1, p2, color, 1);
}

float Bullet::getPosX()
{
	return posX;
}

float Bullet::getPosY()
{
	return posY;
}
