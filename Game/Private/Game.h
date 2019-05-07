//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.h
// definition of MyGame, an implementation of exGameInterface
//

#include "Game/Public/GameInterface.h"
#include "Engine/Public/EngineTypes.h"
#include "Cannon.h"
#include "EnemyTarget.h"
#include "Enemies.h"
#include "Explosion.h"
#include <list>
#include <vector>


//-----------------------------------------------------------------
//-----------------------------------------------------------------

class MyGame : public exGameInterface
{
public:

								MyGame();
	virtual						~MyGame();

	virtual void				Initialize( exEngineInterface* pEngine );

	virtual const char*			GetWindowName() const;
	virtual void				GetClearColor( exColor& color ) const;

	virtual void				OnEvent( SDL_Event* pEvent );
	virtual void				OnEventsConsumed();

	virtual void				Run( float fDeltaT );

private:
	
	void						CheckCollison();

	exEngineInterface*			mEngine;

	int							mFontID;

	bool						mUp;
	bool						mDown;

	bool						click;
	

	vector<EnemyTarget*>		enemyTargets;
	list<Cannon*>				cannons;
	list<Explosion*>			explosions;
	Enemies*					enemy;

	float						bulletSpeed;
	

	exVector2					mTextPosition;

};
