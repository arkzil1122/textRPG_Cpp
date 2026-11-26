#include "Monster.h"

int Monster::GetHP()
{
	return HP;
}

int Monster::GetAtk()
{
	return Atk;
}

int Monster::GetGold()
{
	return Gold;
}

int Monster::GetXP()
{
	return XP;
}

bool Monster::GetisDead()
{
	return isDead;
}

double Monster::GetSpeed()
{
	return Speed;
}

std::string Monster::GetName()
{
	return MonsterName;
}

void Monster::GetDamage(int _damage)
{
	HP -= _damage;
	if (HP <= 0) {
		HP = 0;
		isDead = true;
	}
}

void Monster::InitMonster()
{
	type = MONSTER_NONE;
	isDead = false;
	Level = 1;
}

void Monster::CreateMonster() {
	int monsterNum = utility.RandomRange(int(MONSTER_NONE + 1), int(MONSTER_COUNT - 1));
	SetMonster(MonsterType(monsterNum));
	std::cout << MonsterNameAry[monsterNum] << "이/가 나타났다!" << std::endl;
}

void Monster::SetMonster(MonsterType _type) {
	switch (_type) {
	case MONSTER_SLIME:
		type = MONSTER_SLIME;
		MonsterName = MonsterNameAry[MONSTER_SLIME];
		HP = MaxHP = 10;
		Atk = 3;
		Gold = 5;
		XP = 5;
		Speed = 0.5;
		break;

	case MONSTER_ORC:
		type = MONSTER_ORC;
		MonsterName = MonsterNameAry[MONSTER_ORC];
		HP = MaxHP = 15;
		Atk = 5;
		Gold = 8;
		XP = 8;
		Speed = 0.7;
		break;

	case MONSTER_RABBIT:
		type = MONSTER_RABBIT;
		MonsterName = MonsterNameAry[MONSTER_RABBIT];
		HP = MaxHP = 20;
		Atk = 7;
		Gold = 10;
		XP = 10;
		Speed = 1.5;
		break;

	case MONSTER_DRAGON:
		type = MONSTER_DRAGON;
		MonsterName = MonsterNameAry[MONSTER_DRAGON];
		HP = MaxHP = 25;
		Atk = 10;
		Gold = 13;
		XP = 13;
		Speed = 1.0;
		break;
	}
}


void Monster::Render() {
	std::cout << "==========================" << std::endl;
	std::cout << "종류 : " << MonsterName << std::endl;
	std::cout << "HP : " << HP << " / " << MaxHP;
	std::cout << "\tAtk : " << Atk << std::endl;
	std::cout << "레벨 : " << Level << std::endl;
	std::cout << "==========================" << std::endl;
}