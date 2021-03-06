#pragma once
#include "CupUnit.h"
#include "PhysicsData.h"
#include "Time.h"

constexpr int CBRAKE_DISAPPEAR = 0;

class NormalCup : public CupUnit
{
public:
	NormalCup(Vector2 vec, Vector2 sVec, float sizeX, float sizeY, bool beLiving, int life, int cupHandle);

	void ToggleOnBreak(int brakeMode = 0);

	bool GetBreaking();
	bool GetLiving();

	void Update();
	void Draw();

private:
	bool beBreaking;
	float breakTime, breakTimeMax;
	int posMass[2];
};

