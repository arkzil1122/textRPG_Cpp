#include "Player.h"

void Player::SelectJob()
{
	std::cout << "직업을 선택하세요. (1. 전사\t 2. 궁수 \t 3. 법사)" << std::endl;
	int userInput = utility.ReadInt(1, 3);

	switch (userInput) {
	case JOB_WARRIOR:
		HP = MaxHP = 100;
		Atk = 5;
		JobName = JobNameAry[JOB_WARRIOR];
		break;
	case JOB_ARCHER:
		HP = MaxHP = 70;
		Atk = 7;
		JobName = JobNameAry[JOB_ARCHER];
		break;
	case JOB_MAGE:
		HP = MaxHP = 50;
		Atk = 10;
		JobName = JobNameAry[JOB_MAGE];
		break;
	}
}

void Player::InitPlayer()
{
	HP = 0;
	MaxHP = 0;
	Atk = 0;
	Level = 0;
	MaxXP = 0;
	XP = 0;
	Gold = 0;
}

int Player::GetHP()
{
	return HP;
}

int Player::GetAtk()
{
	return Atk;
}

int Player::GetLevel()
{
	return Level;
}

int Player::GetXP()
{
	return XP;
}

int Player::GetGold()
{
	return Gold;
}

void Player::GetDamage(int _damage)
{
	HP -= _damage;
	if (HP <= 0) {
		HP = 0;
		isDead = true;
	}
	return;
}
