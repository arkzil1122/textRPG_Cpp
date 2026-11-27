#pragma once

#include <iostream>
#include <string>
#include "Utility.h"
#include "Character.h"


enum MonsterType {
	MONSTER_NONE,
	MONSTER_SLIME,
	MONSTER_ORC,
	MONSTER_RABBIT,
	MONSTER_DRAGON,
	MONSTER_COUNT
};

struct MonsterData {
	std::string MonsterName;
	Status status;
	int rewardXP;
	int rewardGold;
};

inline MonsterData MonsterTable[MONSTER_COUNT] = {
	{ "없음",{ 0, 0, 0, 0, 1 }, 0, 0 },
	{ "슬라임",{ 0.5, 10, 10, 3, 1 }, 5, 5 },
	{ "오크",{ 0.7, 15, 15, 5, 1 }, 8, 8 },
	{ "토끼",{ 1.5, 20, 20, 7, 1 }, 10, 10 },
	{ "드래곤",{ 1.0, 25, 25, 10, 1 }, 13, 13 }
};

class Monster : public Character {
private:
	int m_type;
	int m_rewardXP;
	int m_rewardGold;
	

public:
	Monster(MonsterType _type);
	
	MonsterType GetType() const;
	const int& GetRewardXP() const;
	const int& GetRewardGold() const;
	const std::string GetName() const;

	void Render() const;

	~Monster();
};