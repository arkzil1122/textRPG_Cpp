#include "Monster.h"

int Monster::GetHP()
{
    return HP;
}

int Monster::GetAtk()
{
    return Atk;
}

int Monster::GetGold()
{
    return Gold;
}

int Monster::GetXP()
{
    return XP;
}

void Monster::GetDamage(int _damage)
{
    HP -= _damage;
    if (HP <= 0) {
        HP = 0;
        isDead = true;
    }
}
