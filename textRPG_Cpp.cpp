#include <iostream>
#include "Utility.h"
#include "Player.h"
#include "Monster.h"
#include "BattleManager.h"

int main(void) {

	Player player;
	player.InitPlayer();
	player.SelectJob();
	player.Render();

	Monster monster;
	monster.InitMonster();
	monster.CreateMonster();
	monster.Render();

	BattleManager battleManager;
	battleManager.Battle(player, monster);
}