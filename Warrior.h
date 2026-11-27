#pragma once
#include "Player.h"

class Warrior : public Player
{
private:
public:
	Warrior(const std::string& _name);
	
	const std::string GetJobName() const override;
	void Render() const override;
};