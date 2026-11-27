#pragma once
#include "Player.h"

class Archer : public Player
{
private:
public:
	Archer(const std::string& _name);

	const std::string GetJobName() const override;
	void Render() const override;
};