#include "NormalCup.h"

NormalCup::NormalCup(Vector2 vec, Vector2 sVec, float sizeX, float sizeY, bool beLiving, int life, int cupHandle)
	:CupUnit(vec, sVec, sizeX, sizeY, beLiving, life) {

	posMass[0] = 0; // ここは計算必要 外部クラスで計算させる
	posMass[1] = 0;
	this->cupHandle = cupHandle; // ここで外部mapより取得，後に修正必要
	//cupHandle = ImageResize::Resize(cupHandle, (int)sizeX, (int)sizeY);

	beBreaking = FALSE;
	breakTimeMax = 0.5f;
	breakTime = breakTimeMax;
}

void NormalCup::ToggleOnBreak(int brakeMode)
{
	if (beBreaking) return;
	beBreaking = TRUE;
	breakTime = breakTimeMax;
}

bool NormalCup::GetBreaking()
{
	return beBreaking;
}

bool NormalCup::GetLiving()
{
	return beLiving;
}

void NormalCup::Update() { // 重力判定等記述

	if (beBreaking) {
		breakTime -= Time::deltaTime; // 時間によってハンドルを切り替えるもしくは裏の画面でタイル並べて座標指定
		if (breakTime <= 0.00f) {
			beLiving = FALSE;
		}
		return;
	}
	sVec.x += 0.0f;
	sVec.y += Physics::phyG * Time::deltaTime;
	vec.x += sVec.x;
	vec.y += sVec.y;
}

void NormalCup::Draw() {
	if (!beLiving) return;
	//SetDrawArea((int)vec.x - sizeX / 2, (int)vec.y - sizeY / 2, (int)vec.x - sizeX / 2 + (int)sizeX, (int)vec.y - sizeY / 2 + (int)sizeY);
	DrawGraph((int)vec.x - sizeX / 2, (int)vec.y - sizeY / 2, cupHandle, TRUE);

}