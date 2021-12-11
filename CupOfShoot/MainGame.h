#pragma once
#include "GameValue.h"
#include "CupStack.h"
#include "PlayerMob.h"
class MainGame
{
public:
	MainGame(GameValue& gValue);

	void Update();
	void Draw();

private:
	GameValue* gValue{};
	CupStack cStack;
	PlayerMob player;
};

