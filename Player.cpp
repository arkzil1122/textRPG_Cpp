#include "Player.h"

Player::Player()
{
	PlayerJob = JOB_NONE;
	JobName = JobNameAry[JOB_NONE];
	MaxHP = 0;
	HP = 0;
	Atk = 0;
	Level = 1;
	MaxXP = 0;
	XP = 0;
	Gold = 0;
	Speed = 0;
	isDead = false;
}

void Player::SelectJob()
{
	std::cout << "직업을 선택하세요. (1. 전사\t2. 궁수 \t3. 법사)" << std::endl;
	int userInput = Utility::ReadInt(1, 3);

	switch (userInput) {
	case JOB_WARRIOR:
		PlayerJob = JOB_WARRIOR;
		HP = MaxHP = 100;
		Atk = 5;
		JobName = JobNameAry[JOB_WARRIOR];
		Speed = 1.0;
		break;
	case JOB_ARCHER:
		PlayerJob = JOB_ARCHER;
		HP = MaxHP = 70;
		Atk = 7;
		JobName = JobNameAry[JOB_ARCHER];
		Speed = 1.2;
		break;
	case JOB_MAGE:
		PlayerJob = JOB_MAGE;
		HP = MaxHP = 50;
		Atk = 10;
		JobName = JobNameAry[JOB_MAGE];
		Speed = 0.8;
		break;
	}
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

bool Player::GetisDead()
{
	return isDead;
}

double Player::GetSpeed()
{
	return Speed;
}

void Player::TakeDamage(int _damage)
{
	HP -= _damage;
	if (HP <= 0) {
		HP = 0;
		isDead = true;
	}
	return;
}

void Player::Render() {
	std::cout << "==========================" << std::endl;
	std::cout << "직업 : " << JobName << std::endl;
	std::cout << "HP : " << HP << " / " << MaxHP;
	std::cout << "\tAtk : " << Atk << std::endl;
	std::cout << "보유 골드 : " << Gold << "g\t";
	std::cout << "레벨 : " << Level << std::endl;
	std::cout << "경험치 : " << XP << " / " << MaxXP << std::endl;
	std::cout << "==========================" << std::endl;
}