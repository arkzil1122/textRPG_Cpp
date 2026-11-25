#include "Player.h"

int Player::GetHP()
{
    return HP;
}

int Player::GetAtk()
{
    return Atk;
}

int Player::GetLevel()
{
    return Level;
}

int Player::GetXP()
{
    return XP;
}

int Player::GetGold() 
{
    return Gold;
}

void Player::GetDamage(int _damage)
{
    HP -= _damage;
    if (HP <= 0) {
        HP = 0;
        isDead = true;
    }
    return ;
}
