#pragma once
class Monster
{
private:
	int HP;
	int MaxHP;
	int Atk;
	int Gold;
	int XP;
	int Level;
	bool isDead;

public:
	int GetHP();
	int GetAtk();
	int GetGold();
	int GetXP();
	
	void GetDamage(int _damage);
};

