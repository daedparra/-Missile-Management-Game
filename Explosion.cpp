#include "Explosion.h"



Explosion::Explosion(float x, float y)
{
	this->x = x;
	this->y = y;
	this->maxRadius = 15;
	this->radius = maxRadius;
	
	// Color for explosion
	color.mColor[0] = 66;
	color.mColor[1] = 255;
	color.mColor[2] = 211;
	color.mColor[3] = 255;
}


Explosion::~Explosion()
{
}

void Explosion::DrawExplosion(exEngineInterface * mEngine, float time)
{
	// Reducing the size of explosion
	position.x = x;
	position.y = y;
	radius -= time * 10;
	mEngine->DrawCircle(position, radius, color, 0);
}
