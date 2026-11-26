#pragma once

class TimeManager
{
private:
	static unsigned long long s_Now;
	static unsigned long long s_DeltaTime;
	static unsigned long long s_PreTick;
	static unsigned long long s_StartTime;

public:
	static void StartTime();
	static double GetDeltaTime();
	static void UpdateTime();
	static unsigned long long GetBattleTime();
	static unsigned long long GetStartTime();
	static unsigned long long GetPrevTime();
};

