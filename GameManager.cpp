#include "GameManager.h"
#include "Warrior.h"
#include "Archer.h"
#include "Mage.h"


void GameManager::CreatePlayer(PlayerJob _job, std::string _name)
{
	switch (_job) {
	case JOB_WARRIOR:
		player = new Warrior(_name);
		break;
	case JOB_ARCHER:
		player = new Archer(_name);
		break;
	case JOB_MAGE:
		player = new Mage(_name);
		break;
	}
}

// 콘솔 창 크기 및 이런저런 환경설정 실행당 1회
void GameManager::InitGame() {
	Utility::InitRandom();
}

// 새 게임 시작. 모든것을 초기화.
void GameManager::NewGame() {
	delete player;
	delete monster;

	player = nullptr;
	monster = nullptr;

	nowScene = SCENE_JOB_SELECT;
	result = RESULT_NONE;
}

void GameManager::RunGame() {
	nowScene = SCENE_JOB_SELECT;
	while (nowScene != SCENE_EXIT) {
		switch (nowScene) {
		case SCENE_JOB_SELECT:
		{
			std::cout << "직업을 선택하세요. 1. 전사 2. 궁수 3. 법사" << std::endl;
			int userInput = Utility::ReadInt(JOB_NONE + 1, JOB_COUNT - 1);
			CreatePlayer((PlayerJob)userInput, DEFAULT_PLAYER_NAME);
			nowScene = SCENE_ENCOUNTER;
		}
			break;

		case SCENE_ENCOUNTER:
			if (monster != nullptr) {
				delete monster;
			}
			monster = new Monster((MonsterType)Utility::RandomRange(MONSTER_NONE + 1, MONSTER_COUNT - 1));
			std::cout << monster->GetName() << "이/가 나타났다!" << std::endl;
			nowScene = SCENE_BATTLE;
			break;

		case SCENE_BATTLE:
			if (Battle != nullptr) {
				delete Battle;
			}
			Battle = new BattleScene(player, monster);
			result = Battle->RunBattle();
			if (result == RESULT_LOSE) {
				nowScene = SCENE_GAMEOVER;
			}
			else if(result == RESULT_WIN){
				nowScene = SCENE_VICTORY;
			}
			else if (result == RESULT_RUN) {
				nowScene = SCENE_ENCOUNTER;
			}
			break;


		case SCENE_GAMEOVER:
		{
			std::cout << "다시 할거임? 1. Yes  2.No" << std::endl;
			int userInput = Utility::ReadInt(1, 2);
			if (userInput == 1) {
				NewGame();
				nowScene = SCENE_JOB_SELECT;
			}
			else {
				nowScene = SCENE_EXIT;
			}
			break;
		}

		case SCENE_VICTORY:
			std::cout << "미구현" << std::endl;
			system("pause");
			nowScene = SCENE_ENCOUNTER;
			break;

		case SCENE_EXIT:
			std::cout << "게임을 종료합니다." << std::endl;
			system("pause");
			return;
		}
	}
}

// 동적할당 정리
GameManager::~GameManager()
{
	delete monster;
	delete player;
	delete Battle;

	monster = nullptr;
	player = nullptr;
	Battle = nullptr;
}