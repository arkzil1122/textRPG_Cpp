#include "BattleManager.h"

RESULT BattleManager::Battle(Player& _player, Monster& _monster)
{
	RESULT result = RESULT_NONE;
	// 선후공 설정 + Damage에 랜덤 넣을거임.
	while (!_player.GetisDead() || !_monster.GetisDead()) {
		bool isFirst = Utility::RandomRange(false, true);
		
		if (isFirst) {
			// 플레이어 선공
			std::cout << "플레이어의 공격!" << std::endl;
			int damage = _player.GetAtk() + Utility::RandomRange(-2, 2);
			_monster.GetDamage(damage);
			std::cout << _monster.GetName() << "에게 " << damage << "의 피해를 입혔다!" << std::endl;
			if (_monster.GetisDead()) {
				std::cout << _monster.GetName() << "은 쓰러졌다!" << std::endl;
				result = RESULT_WIN;
				break;
			}
		}
		else {
			// 몬스터 선공
			std::cout << _monster.GetName() << "의 공격!" << std::endl;
			int damage = _monster.GetAtk() + Utility::RandomRange(-1, 1);
			_player.GetDamage(damage);
			std::cout << damage << "의 피해를 받았다!" << std::endl;
			if (_player.GetisDead()) {
				std::cout << "You Died." << std::endl;
				result = RESULT_LOSE;
				break;
			}
		}
	}

	return result;
}
