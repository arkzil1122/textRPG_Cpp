#pragma once

#include <iostream>
#include <string>
#include "Utility.h"


enum MonsterType {
	MONSTER_NONE,
	MONSTER_SLIME,
	MONSTER_ORC,
	MONSTER_RABBIT,
	MONSTER_DRAGON,
	MONSTER_COUNT
};

inline std::string MonsterNameAry[MONSTER_COUNT] = {
	"없음",
	"슬라임",
	"오크",
	"토깽",
	"용가리",
};

class Monster
{
private:
	MonsterType type;
	std::string MonsterName;

	int HP;
	int MaxHP;
	int Atk;
	int Gold;
	int XP;
	int Level;
	double Speed;
	bool isDead;

	void SetMonster(MonsterType _type);
public:
	int GetHP();
	int GetAtk();
	int GetGold();
	int GetXP();
	bool GetisDead();
	double GetSpeed();
	std::string GetName();

	void TakeDamage(int _damage);

	void InitMonster();
	void CreateMonster();
	void Render();
};

