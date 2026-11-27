#include "Archer.h"

static const Status ARCHER_BASE_STATUS = {
	1.2, //speed
	80, //maxHP
	80, //HP
	8, //Atk
	1, //Level
};

Archer::Archer(const std::string& _name) : Player(_name, ARCHER_BASE_STATUS)
{
	// 빈 칸.
}

const std::string Archer::GetJobName() const { return "궁수"; }

void Archer::Render() const {
	std::cout << "==========================" << std::endl;
	std::cout << "직업 : " << GetJobName() << std::endl;
	std::cout << "HP : " << m_Status.HP << " / " << m_Status.maxHP;
	std::cout << "\tAtk : " << m_Status.Atk << std::endl;
	std::cout << "보유 골드 : " << GetGold() << "g\t";
	std::cout << "레벨 : " << m_Status.Level << std::endl;
	std::cout << "경험치 : " << GetXP() << " / " << GetMaxXP() << std::endl;
	std::cout << "==========================" << std::endl;
}