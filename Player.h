#pragma once
class Player
{
private:
	int MaxHP;
	int HP;
	int Atk;
	int Level;
	int MaxXP;
	int XP;
	int Gold;
	bool isDead	;

public:
	int GetHP();
	int GetAtk();
	int GetLevel();
	int GetXP();
	int GetGold();

	void GetDamage(int _damage);
};