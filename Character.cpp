#include "Character.h"

Character::Character(std::string _name, Status _status)
{
	m_Name = _name;
	m_Status = _status;
}

const Status& Character::GetStatus() const { return m_Status; }

bool Character::IsDead() const { return m_Status.HP <= 0; }

void Character::TakeDamage(int _damage) {
	m_Status.HP -= _damage;
	if (m_Status.HP <= 0) {
		m_Status.HP = 0;
	}
}

