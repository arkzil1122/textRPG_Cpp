#include <iostream>
#include "Utility.h"
#include "Player.h"
#include "Monster.h"
#include "BattleSystem.h"
#include "BattleScene.h"

int main(void) {
	
	Utility::InitRandom();

	Player player;
	player.InitPlayer();
	player.SelectJob();
	player.Render();

	Monster monster;
	monster.InitMonster();
	monster.CreateMonster();

	BattleScene battle = BattleScene(&player, &monster);
	battle.RunBattle();

	return 0;
}