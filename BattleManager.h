#pragma once

#include "Monster.h"
#include "Player.h"
#include "Utility.h"

enum RESULT {
	RESULT_NONE,
	RESULT_WIN,
	RESULT_RUN,
	RESULT_LOSE,
	RESULT_COUNT
};

class BattleManager
{
private:


public:
	static RESULT Battle(Player& _player, Monster& _monster);
};

