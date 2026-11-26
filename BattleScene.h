#pragma once
#include "Player.h"
#include "Monster.h"
#include "BattleSystem.h"
#include <Windows.h>

#define SCENE_DEALY Sleep(500);

class BattleScene
{
private:
	BattleSystem _system;
	Player* _player;
	Monster* _monster;
	RESULT _result = RESULT_NONE;

public:
	BattleScene(Player* _player, Monster* _monster);

	void StartBattle();
	RESULT RunBattle();
	void DrawBattle();
	BATTLE_ACTION ReadBattleAction();
	void ShowEvent(TurnInfo _info);
	void ShowResult(RESULT _result);
};