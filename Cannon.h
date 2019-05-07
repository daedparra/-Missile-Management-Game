#pragma once
#include "Engine/Public/EngineInterface.h"
#include "Bullet.h"
#include <iostream>
#include <list>
using namespace std;

class Cannon
{
public:
	Cannon(exEngineInterface* mEngine, float posX, float posY);
	~Cannon();

	void DrawCannon(exEngineInterface* mEngine);
	void CheckTrigger(exEngineInterface* mEngine, bool m1, float bulletSpeed, float time);
	void UpdateBulletShot(float time, float bulletSpeed);

	list<Bullet*> bullets;

private:
	exVector2 p1;
	exVector2 p2;

	exColor color;
	float mSize;

	exVector2 HoleP1;
	exVector2 HoleP2;
	exColor	cannonColor;

	float HoleSize;
	
	int cannonCoolDownTime;
	int timer;

};

