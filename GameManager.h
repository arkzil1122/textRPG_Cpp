#pragma once

#include <iostream>
#include <stdlib.h>
#include "Utility.h"
#include "Player.h"
#include "Monster.h"
#include "BattleScene.h"

enum SCENE {
	SCENE_NONE,
	SCENE_JOB_SELECT,
	SCENE_ENCOUNTER,
	SCENE_BATTLE,
	SCENE_GAMEOVER,
	SCENE_VICTORY,
	SCENE_EXIT,
	SCENE_COUNT
};

class GameManager
{
private:
	Player*player = nullptr;
	Monster* monster = nullptr;
	BattleScene* Battle = nullptr;

	RESULT result;
	SCENE nowScene;

	void CreatePlayer(PlayerJob _job, std::string _name);

public:
	void InitGame();
	void NewGame();
	void RunGame();

	~GameManager();
};

