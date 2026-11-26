#pragma once

#include <vector>
#include "Monster.h"
#include "Player.h"
#include "Utility.h"
#include "TimeManager.h"


enum RESULT {
	RESULT_NONE,
	RESULT_WIN,
	RESULT_RUN,
	RESULT_LOSE,
	RESULT_COUNT
};

enum BATTLE_ACTION {
	BATTLE_ACTION_NONE,
	BATTLE_ACTION_ATTACK,
	BATTLE_ACTION_SKILL,
	BATTLE_ACTION_DEFENCE,
	BATTLE_ACTION_RUN,
	BATTLE_ACTION_COUNT
};

enum BATTLE_EVENT {
	BATTLE_EVENT_NONE,
	BATTLE_EVENT_ATTACK,
	BATTLE_EVENT_SKILL_LOCKED,
	BATTLE_EVENT_DEFEND,
	BATTLE_EVENT_RUN_SUCCESS,
	BATTLE_EVENT_RUN_FAIL,
	BATTLE_EVENT_COUNT
};

enum ACTOR {
	ACTOR_NONE,
	ACTOR_PLAYER,
	ACTOR_MONSTER,
	ACTOR_COUNT
};

struct TurnInfo {
	ACTOR _turnActor = ACTOR_NONE;
	int _turnDamage = 0;
	BATTLE_EVENT _turnEvent = BATTLE_EVENT_NONE;
};

class BattleSystem
{
private:
	const double ACTION_POINT_MAX = 1;
	double _playerActionPoint = 0;
	double _monsterActionPoint = 0;
	Player* _player = nullptr;
	Monster* _monster = nullptr;
	bool _isDefend = false;
	RESULT _result = RESULT_NONE;
	TurnInfo _info;

	void UseActionPoint(ACTOR _actor);
	int SetDamage(ACTOR _actor);
	RESULT CheckResult();

public:
	void BattleInit(Player* _player, Monster* _monster);
	
	void InitTurnInfo();
	ACTOR NextActor();
	void PlayerAction(BATTLE_ACTION _action);
	void MonsterAction();

	RESULT GetResult();
	TurnInfo GetTurnInfo();
	double GetPlayerActionPoint();
	double GetMonsterActionPoint();

	RESULT BattleByTime(Player& _player, Monster& _monster);
};

