#pragma once

#include <iostream>
#include <string>
#include "Character.h"
#include "Utility.h"

#define DEFAULT_PLAYER_NAME "철수"

enum PlayerJob {
	JOB_NONE,
	JOB_WARRIOR,
	JOB_ARCHER,
	JOB_MAGE,

	JOB_COUNT
};

inline std::string JobNameAry[JOB_COUNT] = {
	"백수",
	"전사",
	"궁수",
	"법사",
};

class Player : public Character {
private:
	int m_XP;
	int m_MaxXP;
	int m_Gold;

	void LevelUp();
	PlayerJob m_Job;

	//int virtual StatusGrowth() = 0;

public:
	Player(std::string _name, Status _status);

	void SelectJob();
	void GainGold(int _reward);
	void GainXP(int _reward);

	const int&  GetGold() const;
	const int& GetXP() const;
	const int& GetMaxXP() const;

	//TODO : 자식들 가상함수 선언
	//void virtual UseSkill(Character& _target) = 0;

	virtual void Render() const = 0;
	virtual const std::string GetJobName() const = 0;

	virtual ~Player();
};