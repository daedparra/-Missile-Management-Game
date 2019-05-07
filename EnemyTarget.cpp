#include "EnemyTarget.h"


EnemyTarget::
EnemyTarget(float posX, float posY)
{
	this->posX = posX;
	this->posY = posY;
}

EnemyTarget::~EnemyTarget()
{
}

void EnemyTarget::RenderEnemy(exEngineInterface * mEngine)
{
	mSizeX = 50;
	mSizeY = 25;

	p1.x = posX + mSizeX / 2;
	p2.x = posX - mSizeX / 2;

	p1.y = posY + mSizeY / 2;
	p2.y = posY - mSizeY / 2;


	color.mColor[0] = 180;
	color.mColor[1] = 254;
	color.mColor[2] = 0;
	color.mColor[3] = 255;

	mEngine->DrawBox(p1, p2, color, 2);
}

float EnemyTarget::getPosX()
{
	return posX;
}

float EnemyTarget::getPosY()
{
	return posY;
}
