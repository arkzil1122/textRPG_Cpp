#pragma once

#include <iostream>
#include <string>
#include "Utility.h"

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
	double Speed;
	bool isDead	;

public:

	Player();

	void SelectJob();

	int GetHP();
	int GetAtk();
	int GetLevel();
	int GetXP();
	int GetGold();
	bool GetisDead();
	double GetSpeed();

	void TakeDamage(int _damage);
	
	void Render();
};