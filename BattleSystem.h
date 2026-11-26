#pragma once

#include "Monster.h"
#include "Player.h"
#include "Utility.h"
#include "TimeManager.h"

#define ACTION_TIME 1

enum RESULT {
	RESULT_NONE,
	RESULT_WIN,
	RESULT_RUN,
	RESULT_LOSE,
	RESULT_COUNT
};

class BattleSystem
{
private:


public:
	static RESULT BattleByTime(Player& _player, Monster& _monster);
};

