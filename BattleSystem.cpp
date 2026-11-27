#include "BattleSystem.h"

void BattleSystem::BattleInit(Player* _player, Monster* _monster)
{
	_playerActionPoint = 0;
	_monsterActionPoint = 0;
	_isDefend = 0;
	_result = RESULT_NONE;

	this->_player = _player;
	this->_monster = _monster;

}

void BattleSystem::InitTurnInfo()
{
	_info._turnActor = ACTOR_NONE;
	_info._turnDamage = 0;
	_info._turnEvent = BATTLE_EVENT_NONE;
}

ACTOR BattleSystem::NextActor()
{
	if (_player->GetSpeed() <= 0 && _monster->GetSpeed() <= 0) {
		return ACTOR_PLAYER;
	}
	while (_playerActionPoint < ACTION_POINT_MAX && _monsterActionPoint < ACTION_POINT_MAX) {
		_playerActionPoint += _player->GetSpeed();
		_monsterActionPoint += _monster->GetSpeed();
	}
	if (_playerActionPoint >= ACTION_POINT_MAX && _monsterActionPoint >= ACTION_POINT_MAX) {
		return _playerActionPoint >= _monsterActionPoint ? ACTOR_PLAYER : ACTOR_MONSTER;
	}
	else {
		if (_playerActionPoint >= ACTION_POINT_MAX) {
			return ACTOR_PLAYER;
		}
		else {
			return ACTOR_MONSTER;
		}
	}
}

// Player의 행동 -> 사건 반환
void BattleSystem::PlayerAction(BATTLE_ACTION _action)
{
	_info._turnActor = ACTOR_PLAYER;
	_info._turnEvent = BATTLE_EVENT_NONE;

	switch (_action) {
	case BATTLE_ACTION_ATTACK:
		{
			int damage = SetDamage(_info._turnActor);
			_monster->TakeDamage(damage);
			_info._turnEvent = BATTLE_EVENT_ATTACK;
			_info._turnDamage = damage;
			break;
		}

	case BATTLE_ACTION_SKILL:
		_info._turnEvent = BATTLE_EVENT_SKILL_LOCKED;
		return;

	case BATTLE_ACTION_DEFENCE:
		_isDefend = true;
		_info._turnEvent = BATTLE_EVENT_DEFEND;
		break;

	case BATTLE_ACTION_RUN:
		{
			bool isSuccess = Utility::RandomRange(false, true);
			if (isSuccess) {
				_info._turnEvent = BATTLE_EVENT_RUN_SUCCESS;
				_result = RESULT_RUN;
			}
			else {
				_info._turnEvent = BATTLE_EVENT_RUN_FAIL;
			}
		}
	}

	UseActionPoint(_info._turnActor);
	CheckResult();

	return;
}

// Monster의 행동 -> 사건 반환
void BattleSystem::MonsterAction()
{
	_info._turnEvent = BATTLE_EVENT_ATTACK;
	_info._turnActor = ACTOR_MONSTER;

	int damage = SetDamage(_info._turnActor);

	if (_isDefend) {
		damage = damage / 2;
		_isDefend = false;
	}
	_player->TakeDamage(damage);

	_info._turnDamage = damage;
	UseActionPoint(_info._turnActor);
	CheckResult();

	return;
}

RESULT BattleSystem::GetResult()
{
	return _result;
}

TurnInfo BattleSystem::GetTurnInfo()
{
	return _info;
}

double BattleSystem::GetPlayerActionPoint()
{
	return _playerActionPoint;
}

double BattleSystem::GetMonsterActionPoint()
{
	return _monsterActionPoint;
}

RESULT BattleSystem::CheckResult()
{
	if (_result != RESULT_NONE) {
		return _result;
	}
	if (_monster->GetisDead()) {
		_result = RESULT_WIN;
	}
	else if (_player->GetisDead()) {
		_result = RESULT_LOSE;
	}
	return _result;
}

RESULT BattleSystem::BattleByTime(Player& _player, Monster& _monster) {
	RESULT result = RESULT_NONE;
	TimeManager::StartTime();
	double PlayerAction = 0;
	double MonsterAction = 0;
	int damage = 0;
	while (!_player.GetisDead() && !_monster.GetisDead()) {
		PlayerAction += TimeManager::GetDeltaTime() * _player.GetSpeed();
		MonsterAction += TimeManager::GetDeltaTime() * _monster.GetSpeed();

		if (PlayerAction >= ACTION_POINT_MAX) {
			damage = _player.GetAtk() + Utility::RandomRange(-2, 2);
			
			std::cout << "\n플레이어의 공격!" << std::endl;
			_monster.TakeDamage(damage);
			std::cout << damage << "의 데미지를 입혔다!" << std::endl;
			PlayerAction -= ACTION_POINT_MAX;

			if (_monster.GetisDead()) {
				std::cout << _monster.GetName() << "이/가 쓰러졌다!" << std::endl;
				result = RESULT_WIN;
				break;
			}
		}
		if (MonsterAction >= ACTION_POINT_MAX) {
			damage = _monster.GetAtk() + Utility::RandomRange(-1, 1);
			std::cout << '\n' << _monster.GetName() << "의 공격!" << std::endl;
			_player.TakeDamage(damage);
			std::cout << damage << "의 피해를 입었다!" << std::endl;
			MonsterAction -= ACTION_POINT_MAX;
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

void BattleSystem::UseActionPoint(ACTOR _actor)
{
	if (_actor == ACTOR_PLAYER) {
		_playerActionPoint -= ACTION_POINT_MAX;
	}
	else {
		_monsterActionPoint -= ACTION_POINT_MAX;
	}
}

int BattleSystem::SetDamage(ACTOR _actor)
{
	if (_actor == ACTOR_PLAYER) {
		return _player->GetAtk() + Utility::RandomRange(-2, 2);
	}
	else {
		return _monster->GetAtk() + Utility::RandomRange(-1, 1);
	}
}