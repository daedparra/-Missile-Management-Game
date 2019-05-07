#include "Cannon.h"
#include "Windows.h"


Cannon::Cannon(exEngineInterface * mEngine, float posX, float posY)
{
	this->mSize = 50;

	p1.x = posX + mSize / 2;
	p2.x = posX - mSize / 2;


	p1.y = posY + mSize / 2;
	p2.y = posY - mSize / 2;


	color.mColor[0] = 2;
	color.mColor[1] = 123;
	color.mColor[2] = 255;
	color.mColor[3] = 255;
	
	HoleSize = 10;
	HoleP1.x = posX + HoleSize / 2;
	HoleP2.x = posX - HoleSize / 2;
	
	float offset = 40;
	
	HoleP1.y = posY + HoleSize / 2 - offset;
	HoleP2.y = posY - HoleSize / 2 + 100;

	cannonColor.mColor[0] = 255;
	cannonColor.mColor[1] = 0;
	cannonColor.mColor[2] = 0;
	cannonColor.mColor[3] = 255;
	cannonCoolDownTime = 1;
	timer = 0;
}

Cannon::~Cannon()
{
}

void Cannon::UpdateBulletShot(float time, float bulletSpeed)
{
	for (list<Bullet*>::iterator pointer = bullets.begin(); pointer != bullets.end();)
	{
		if ((*pointer)->getPosX() > kViewportWidth || (*pointer)->getPosX() < 0 || (*pointer)->getPosY() < 0)
		{
			pointer = bullets.erase(pointer);
		}
		else
		{
			(*pointer)->ShootMissile(time, bulletSpeed, color);
			++pointer;
		}
	}
}

void Cannon::CheckTrigger(exEngineInterface * mEngine, bool m1, float bulletSpeed, float time)
{
	bool shootClicked = false;

	shootClicked = m1;

	if (shootClicked)
	{
		if (timer > cannonCoolDownTime)
		{
			Bullet* bullet = new Bullet(mEngine, (p1.x + p2.x) / 2, HoleP1.y - 11, -1, -1);
			if (bullets.size() < 1)
			{
				bullets.push_back(bullet);
			}
			timer = 0;
		}
		else
		{
			timer += 1;
		}
	}
	UpdateBulletShot(time, bulletSpeed);
}

void Cannon::DrawCannon(exEngineInterface * mEngine)
{
	mEngine->DrawBox(HoleP1, HoleP2, cannonColor, 0);
}


