//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.cpp
// implementation of MyGame, an implementation of exGameInterface
//

#include "Game/Private/Game.h"

#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"


//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* gWindowName = "";

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::MyGame()
	: mEngine( nullptr )
	, mFontID( -1 )
	, mUp( false )
	, mDown( false )
	, click(false)
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::~MyGame()
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Initialize( exEngineInterface* pEngine )
{
	mEngine = pEngine;

	mFontID = mEngine->LoadFont( "afternight.ttf", 32 );

	mTextPosition.x = 50.0f;
	mTextPosition.y = 50.0f;

	bulletSpeed = 800;


	// Adding three Enemies Targets
	enemyTargets.push_back(new EnemyTarget(170, kViewportHeight - 100));
	enemyTargets.push_back(new EnemyTarget(250, kViewportHeight - 100));
	enemyTargets.push_back(new EnemyTarget(330, kViewportHeight - 100));
	enemyTargets.push_back(new EnemyTarget(kViewportWidth - 170, kViewportHeight - 100));
	enemyTargets.push_back(new EnemyTarget(kViewportWidth - 250, kViewportHeight - 100));
	enemyTargets.push_back(new EnemyTarget(kViewportWidth - 330, kViewportHeight - 100));


	// Adding Cannon to the Scene
	cannons.push_back(new Cannon(mEngine, kViewportWidth / 2, kViewportHeight - 100));

	enemy = new Enemies();

}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* MyGame::GetWindowName() const
{
	return gWindowName;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::GetClearColor( exColor& color ) const
{
	color.mColor[0] = 128;
	color.mColor[1] = 128;
	color.mColor[2] = 128;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEvent( SDL_Event* pEvent )
{
	click = pEvent->type == SDL_MOUSEBUTTONDOWN;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEventsConsumed()
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Run( float fDeltaT )
{
	
	//Draw background
	exVector2 backgroundP1;
	backgroundP1.x = 0;
	backgroundP1.y = 0;

	exVector2 backgroundP2;
	backgroundP2.x = kViewportWidth;
	backgroundP2.y = kViewportHeight;

	exColor backgroundColor;
	backgroundColor.mColor[0] = 0;
	backgroundColor.mColor[1] = 0;
	backgroundColor.mColor[2] = 0;
	backgroundColor.mColor[3] = 255;

	mEngine->DrawBox(backgroundP1, backgroundP2, backgroundColor, 2);
	// Drawing the Cannons
	for (list<Cannon*>::iterator it = cannons.begin(); it != cannons.end(); it++)
	{
		(*it)->DrawCannon(mEngine);
		(*it)->CheckTrigger(mEngine, click, bulletSpeed, fDeltaT);
	}

	// Drawing the Enemies
	for (vector<EnemyTarget*>::iterator it = enemyTargets.begin(); it != enemyTargets.end(); it++)
	{
		(*it)->RenderEnemy(mEngine);
	}

	// Letting enemies shoot
	enemy->ShootMissle(mEngine, fDeltaT, enemyTargets);

	CheckCollison();
	for (list<Explosion*>::iterator it = explosions.begin(); it != explosions.end(); it++)
	{
		(*it)->DrawExplosion(mEngine, fDeltaT);
	}
	
}


void MyGame::CheckCollison()
{
	float enemeyBullHitSize = 20;
	bool erase = false;


	//for (auto& enemyBullet : enemy->bullets)
	//{
	//	for (auto& cannon : cannons)
	//	{
	//		for (auto& playerBullet : cannon->bullets.begin)
	//		{
	//		
	//		}

	//	}

	//}



	//auto enemyBulletAuto&: list<Bullet*>::iterator();

	for (list<Bullet*>::iterator enemybullet = enemy->bullets.begin(); enemybullet != enemy->bullets.end();)
	{
		for (list<Cannon*>::iterator cannonIt = cannons.begin(); cannonIt != cannons.end();)
		{
			for (list<Bullet*>::iterator playerBullet = (*cannonIt)->bullets.begin(); playerBullet != (*cannonIt)->bullets.end();)
			{
				if (((*playerBullet)->getPosX() > (*enemybullet)->getPosX() - enemeyBullHitSize) &&
					((*playerBullet)->getPosX() < (*enemybullet)->getPosX() + enemeyBullHitSize) &&
					((*playerBullet)->getPosY() > (*enemybullet)->getPosY() - enemeyBullHitSize) &&
					((*playerBullet)->getPosY() < (*enemybullet)->getPosY() + enemeyBullHitSize))
				{
					explosions.push_back(new Explosion((*playerBullet)->getPosX(), (*playerBullet)->getPosY()));
					playerBullet = (*cannonIt)->bullets.erase(playerBullet);
					enemybullet = enemy->bullets.erase(enemybullet);
				}
				else
				{
					++playerBullet;
				}
			}

			if (cannonIt != cannons.end())
			{
				++cannonIt;
			}
		}
		if (enemybullet != enemy->bullets.end())
		{
			++enemybullet;
		}
	}

	for (list<Bullet*>::iterator enemyBullet = enemy->bullets.begin(); enemyBullet != enemy->bullets.end();)
	{
		for (vector<EnemyTarget*>::iterator enemyTarget = enemyTargets.begin(); enemyTarget != enemyTargets.end();)
		{
			if (((*enemyTarget)->getPosX() > (*enemyBullet)->getPosX() - enemeyBullHitSize) &&
				((*enemyTarget)->getPosX() < (*enemyBullet)->getPosX() + enemeyBullHitSize) &&
				((*enemyTarget)->getPosY() > (*enemyBullet)->getPosY() - enemeyBullHitSize) &&
				((*enemyTarget)->getPosY() < (*enemyBullet)->getPosY() + enemeyBullHitSize))
			{
				explosions.push_back(new Explosion((*enemyBullet)->getPosX(), (*enemyBullet)->getPosY()));
				enemyTarget = enemyTargets.erase(enemyTarget);
				enemyBullet = enemy->bullets.erase(enemyBullet);
			}
			else
			{
				++enemyTarget;
			}
		}
		++enemyBullet;
	}

}