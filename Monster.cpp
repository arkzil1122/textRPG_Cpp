#include "Monster.h"

Monster::Monster(MonsterType _type) : Character(MonsterTable[_type].MonsterName, MonsterTable[_type].status)
{
	const MonsterData& data = MonsterTable[_type];

	m_type = _type;
	m_Name = data.MonsterName;
	m_Status = data.status;
	m_rewardXP = data.rewardXP;
	m_rewardGold = data.rewardGold;
}

const std::string Monster::GetName() const
{
	return MonsterTable[m_type].MonsterName;
}

void Monster::Render() const {
	std::cout << "==========================" << std::endl;
	std::cout << "종류 : " <<  m_Name << std::endl;
	std::cout << "HP : " << m_Status.HP << " / " << m_Status.maxHP;
	std::cout << "\tAtk : " << m_Status.Atk << std::endl;
	std::cout << "레벨 : " << m_Status.Level << std::endl;
	std::cout << "==========================" << std::endl;
}

Monster::~Monster()
{
}
