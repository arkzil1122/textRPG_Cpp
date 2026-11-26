#include "BattleScene.h"

RESULT BattleScene::RunBattle()
{
	_system.BattleInit(_player,  _monster);
	DrawBattle();
	SCENE_DEALY;
	while (_result == RESULT_NONE) {
		_system.InitTurnInfo();
		if (_system.NextActor() == ACTOR_PLAYER) {
			_system.PlayerAction(ReadBattleAction());
		}
		else {
			_system.MonsterAction();
			SCENE_DEALY;
		}
		DrawBattle();
		ShowEvent(_system.GetTurnInfo());
		_result = _system.GetResult();
		SCENE_DEALY;
	}
	ShowResult(_result);
	return _result;
}

BattleScene::BattleScene(Player* _player, Monster* _monster)
{
	this->_player = _player;
	this->_monster = _monster;
}


void BattleScene::DrawBattle()
{
	system("cls");
	_player->Render();
	_monster->Render();
	std::cout << "\n무엇을 할까?" << std::endl;
	std::cout << "1. 공격\t2.스킬\t3.방어\t4.도망" << std::endl;
}

BATTLE_ACTION BattleScene::ReadBattleAction()
{
	BATTLE_ACTION _action =
		(BATTLE_ACTION) Utility::ReadInt(BATTLE_ACTION_NONE + 1, BATTLE_ACTION_COUNT - 1);
	return _action;
}

void BattleScene::ShowEvent(TurnInfo _info)
{
	switch (_info._turnEvent) {
	case BATTLE_EVENT_ATTACK:
		if (_info._turnActor == ACTOR_MONSTER) {
			std::cout << _monster->GetName() << "의 공격!" << std::endl;
			std::cout << _info._turnDamage << "의 데미지를 입었다!" << std::endl;
			SCENE_DEALY;
		}
		else {
			std::cout << "플레이어의 공격!" << std::endl;
			std::cout << _info._turnDamage << "의 데미지를 입혔다!" << std::endl;
			SCENE_DEALY;
		}
		break;
	case BATTLE_EVENT_DEFEND:
		std::cout << _info._turnActor << "는 방어태세를 취했다!(받는 피해 감소 -50%)" << std::endl;
		SCENE_DEALY;
		break;
	case BATTLE_EVENT_RUN_FAIL:
		std::cout << "도망칠 수 없었다!" << std::endl;
		SCENE_DEALY;
		break;
	case BATTLE_EVENT_SKILL_LOCKED:
		std::cout << "스킬 기능 미구현" << std::endl;
		SCENE_DEALY;
		break;
	}
}

void BattleScene::ShowResult(RESULT _result)
{
	switch (_result) {
	case RESULT_WIN:
		std::cout << _monster->GetName() << "이/가 쓰러졌다!" << std::endl;
		// 이런저런 처리(경험치, 골드, 재도전)
		SCENE_DEALY;
		break;

	case RESULT_LOSE:
		std::cout << "You Died." << std::endl;
		std::cout << "당신은 " << _monster->GetName() << "에게 패배했다.";
		std::cout << "(남은 체력 : " << _monster->GetHP() << ")" << std::endl;
		SCENE_DEALY;
		// 재도전?
		break;

	case RESULT_RUN:
		std::cout << "무사히 도망쳤다!" << std::endl;
		SCENE_DEALY;
		break;
	}
}
