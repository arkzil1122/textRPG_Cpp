#include "Warrior.h"

static const Status WARRIOR_BASE_STATUS = {
	1.0, //speed
	100, //maxHP
	100, //HP
	10, //Atk
	1, //Level
};

Warrior::Warrior(const std::string& _name) : Player(_name, WARRIOR_BASE_STATUS)
{
	// 빈 칸.
}

const std::string Warrior::GetJobName() const { return "전사"; }

void Warrior::Render() const {
	std::cout << "==========================" << std::endl;
	std::cout << "직업 : " << GetJobName() << std::endl;
	std::cout << "HP : " << m_Status.HP << " / " << m_Status.maxHP;
	std::cout << "\tAtk : " << m_Status.Atk << std::endl;
	std::cout << "보유 골드 : " << GetGold() << "g\t";
	std::cout << "레벨 : " << m_Status.Level << std::endl;
	std::cout << "경험치 : " << GetXP() << " / " << GetMaxXP() << std::endl;
	std::cout << "==========================" << std::endl;
}