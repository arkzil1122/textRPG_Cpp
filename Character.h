#pragma once
#include <string>
struct Status {
	double Speed;
	int maxHP;
	int HP;
	int Atk;
	int Level;
};

class Character
{
protected:
	Character(std::string _name, Status _status);
	Status m_Status;
	std::string m_Name;

public:
	const Status& GetStatus() const;
	bool IsDead() const;
	void TakeDamage(int _damage);
	
	//void virtual Render() const = 0;

	virtual ~Character() = default;
};

