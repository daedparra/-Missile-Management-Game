#pragma once
#include "Bullet.h"
#include "EnemyTarget.h"
#include <vector>
#include <list>

using namespace std;
class Enemies
{
public:
	Enemies();
	~Enemies();

	void ShootMissle(exEngineInterface* mEngine, float time, vector<EnemyTarget*> enemyTargets);
	void UpdateBulletShot(float time, float bulletSpeed);

	list<Bullet*> bullets;
private:

	int timer;
	int enemyCoolDownTime;
	float bulletSpeed;
	exColor enemyBulletColor;

};

