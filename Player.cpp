#include "Player.h"

Player::Player(std::string _name, Status _status) :Character(_name, _status) {
	m_Name = "철수";
	m_Status = _status;
	m_XP = 0;
	m_MaxXP = 0;
	m_Gold = 0;
	m_Job = JOB_NONE;
}

const int& Player::GetGold() const { return m_Gold; };
const int& Player::GetXP() const { return m_XP; };
const int& Player::GetMaxXP() const { return m_MaxXP; }

Player::~Player()
{
}
