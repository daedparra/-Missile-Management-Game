#pragma once
#include "Engine/Public/EngineInterface.h"


class Explosion
{
public:
	Explosion(float x, float y);
	~Explosion();

	void DrawExplosion(exEngineInterface* mEngine, float time);

private:
	exVector2 position;
	exColor	  color,color1,color2;
	float x;
	float y;
	float maxRadius;
	float radius;
};

