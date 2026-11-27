#include "Mage.h"

static const Status MAGE_BASE_STATUS = {
	0.7, //speed
	70, //maxHP
	700, //HP
	15, //Atk
	1, //Level
};

Mage::Mage(const std::string & _name) : Player(_name, MAGE_BASE_STATUS)
{
	// 빈 칸.
}

const std::string Mage::GetJobName() const { return "법사"; }

void Mage::Render() const {
	std::cout << "==========================" << std::endl;
	std::cout << "직업 : " <<  GetJobName() << std::endl;
	std::cout << "HP : " << m_Status.HP << " / " << m_Status.maxHP;
	std::cout << "\tAtk : " << m_Status.Atk << std::endl;
	std::cout << "보유 골드 : " << GetGold() << "g\t";
	std::cout << "레벨 : " << m_Status.Level << std::endl;
	std::cout << "경험치 : " << GetXP() << " / " << GetMaxXP() << std::endl;
	std::cout << "==========================" << std::endl;
}