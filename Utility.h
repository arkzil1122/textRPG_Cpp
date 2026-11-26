#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

class Utility
{
public:
	static void InitRandom();
	static int ReadInt(int _min, int _max);
	static int RandomRange(int _min, int _max);
};

