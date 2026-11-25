#pragma once

#include <iostream>
#include <string>
#include "Utility.h"

inline Utility utility;

enum PlayerJob {
	JOB_NONE,
	JOB_WARRIOR,
	JOB_ARCHER,
	JOB_MAGE,
	JOB_COUNT
};

inline std::string JobNameAry[JOB_COUNT] = {
	"백수",
	"전사",
	"궁수",
	"법사",
};

class Player
{
private:
	PlayerJob PlayerJob;
	std::string JobName;
	int MaxHP;
	int HP;
	int Atk;
	int Level;
	int MaxXP;
	int XP;
	int Gold;
	bool isDead	;

public:
	void SelectJob();
	void InitPlayer();

	int GetHP();
	int GetAtk();
	int GetLevel();
	int GetXP();
	int GetGold();
	bool GetisDead();

	void GetDamage(int _damage);
	
	void Render();
};