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

RESULT BattleManager::BattleByTime(Player& _player, Monster& _monster) {
	RESULT result = RESULT_NONE;
	TimeManager::StartTime();
	double PlayerAction = 0;
	double MonsterAction = 0;
	int damage = 0;
	while (!_player.GetisDead() && !_player.GetisDead()) {
		PlayerAction += TimeManager::GetDeltaTime() * _player.GetSpeed();
		MonsterAction += TimeManager::GetDeltaTime() * _monster.GetSpeed();

		if (PlayerAction >= ACTION_TIME) {
			damage = _player.GetAtk() + Utility::RandomRange(-2, 2);
			
			std::cout << "\n플레이어의 공격!" << std::endl;
			_monster.GetDamage(damage);
			std::cout << damage << "의 데미지를 입혔다!" << std::endl;
			PlayerAction -= ACTION_TIME;

			if (_monster.GetisDead()) {
				std::cout << _monster.GetName() << "이/가 쓰러졌다!" << std::endl;
				result = RESULT_WIN;
				break;
			}
		}
		if (MonsterAction >= ACTION_TIME) {
			damage = _monster.GetAtk() + Utility::RandomRange(-1, 1);
			std::cout << '\n' << _monster.GetName() << "의 공격!" << std::endl;
			_player.GetDamage(damage);
			std::cout << damage << "의 피해를 입었다!" << std::endl;
			MonsterAction -= ACTION_TIME;
			if (_player.GetisDead()) {
				std::cout << "You Died" << std::endl;
				result = RESULT_LOSE;
				break;
			}
		}
		TimeManager::UpdateTime();
	}

	return result;
}