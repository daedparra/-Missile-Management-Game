#pragma once
#include "Engine/Public/EngineInterface.h"


class EnemyTarget
{
public:
	EnemyTarget(float posX, float posY);
	~EnemyTarget();

	void RenderEnemy(exEngineInterface* mEngine);

	float getPosX();
	float getPosY();

private:
	float posX;
	float posY;

	exVector2 p1;
	exVector2 p2;
	exColor color;

	float mSizeX;
	float mSizeY;
};

