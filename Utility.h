#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

class Utility
{
public:
	void InitRandom();
	int ReadInt(int _min, int _max);
	int RandomRange(int _min, int _max);
};

