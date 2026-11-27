#pragma once
#include "Player.h"

class Mage : public Player
{
private:
public:
	Mage(const std::string& _name);

	const std::string GetJobName() const override;
	void Render() const override;
};