#include "TimeManager.h"
#include <Windows.h>

// static 멤버 변수는 반드시 정의 해줄 것.
unsigned long long TimeManager::s_Now = 0;
unsigned long long TimeManager::s_DeltaTime = 0;
unsigned long long TimeManager::s_PreTick = 0;
unsigned long long TimeManager::s_StartTime = 0;

void TimeManager::StartTime()
{
	s_StartTime = GetTickCount64();
	s_PreTick = s_Now = s_DeltaTime = 0;
}

double TimeManager::GetDeltaTime()
{
	return s_DeltaTime * 0.001;
}

void TimeManager::UpdateTime()
{
	s_Now = GetTickCount64() - s_StartTime;
	s_DeltaTime = s_Now - s_PreTick;
	s_PreTick = s_Now;
	Sleep(500);
}

unsigned long long TimeManager::GetBattleTime()
{
	return s_Now;
}

unsigned long long TimeManager::GetStartTime()
{
	return s_StartTime;
}

unsigned long long TimeManager::GetPrevTime()
{
	return s_PreTick;
}