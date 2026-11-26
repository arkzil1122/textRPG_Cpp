#include <iostream>
#include "Utility.h"
#include "Player.h"
#include "Monster.h"
#include "BattleSystem.h"

int main(void) {
	
	Utility::InitRandom();

	Player player;
	player.InitPlayer();
	player.SelectJob();
	player.Render();

	Monster monster;
	monster.InitMonster();
	monster.CreateMonster();
	monster.Render();

	BattleSystem::BattleByTime(player, monster);
}