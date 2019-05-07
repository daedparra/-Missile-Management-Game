#pragma once

#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"
#include <iterator>
#include <math.h>


class Bullet
{
public:
	Bullet(exEngineInterface* mEngine, float startX, float startY, float destX, float destY);
	~Bullet();

	void CalculateXYDirection(float startX, float startY, float destX, float destY);
	void ShootMissile(float time, float speed, exColor color);

	void DrawBullet(exColor color);

	float getPosX();
	float getPosY();

private:
	exVector2 p1;
	exVector2 p2;

	float mSizeX;
	float mSizeY;
	float posX;
	float posY;
	float startPosX;
	float startPosY;

	float directionX;
	float directionY;

	float currentSpeedY;
	exEngineInterface* mEngine;
};

