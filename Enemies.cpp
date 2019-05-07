#include "Enemies.h"

Enemies::Enemies()
{
	
	this->enemyBulletColor.mColor[0] = 249;
	this->enemyBulletColor.mColor[1] = 143;
	this->enemyBulletColor.mColor[2] = 254;
	this->enemyBulletColor.mColor[3] = 255;
	this->enemyCoolDownTime = 100;
	this->timer = 0;
	this->bulletSpeed = 50;
}


Enemies::~Enemies()
{
}

void Enemies::ShootMissle(exEngineInterface * mEngine, float time, vector<EnemyTarget*> enemyTargets)
{
	if (timer > enemyCoolDownTime) 
	{
		int Shot = rand() % 2 + 1;

		for (int i = 0; i < Shot; i++)
		{
			if (enemyTargets.size() != 0)
			{
				int enemyTarget = rand() % enemyTargets.size();
				vector<EnemyTarget*>::iterator pointer = enemyTargets.begin() + enemyTarget;

				Bullet* bullet = new Bullet(mEngine, rand() % kViewportWidth, 20, (*pointer)->getPosX(), (*pointer)->getPosY());

				bullets.push_back(bullet);
				timer = 0;
			}
			
		}
	}
	else 
	{
		timer += 1;
	}
	UpdateBulletShot(time, bulletSpeed);
}

void Enemies::UpdateBulletShot(float time, float bulletSpeed)
{
	for(list<Bullet*>::iterator pointer = bullets.begin(); pointer != bullets.end();)
	{
		if ((*pointer)->getPosX() > kViewportWidth || (*pointer)->getPosX() < 0 || (*pointer)->getPosY() > kViewportHeight - 100)
		{
			pointer = bullets.erase(pointer);
		}
		else 
		{
			(*pointer)->ShootMissile(time, bulletSpeed, enemyBulletColor);
			++pointer;
		}
	}
}
