#include "Utility.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
// min ~ max 사이의 입력값 반환
int Utility::ReadInt(int _min, int _max)
{
	int userInput = 0;
	while (true)
	 {
		std::cout << "값을 입력하세요 : ";

		bool isNumber = bool(std::cin >> userInput);
		bool isEnd = isNumber && std::cin.peek() == '\n';
		if (!isEnd || !isNumber) {
			std::cout << "숫자만 입력하세요." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		bool isRange = isEnd && _min <= userInput && userInput <= _max;

		if (!isRange) {
			std::cout << "잘못된 입력입니다." << std::endl;
			std::cout << _min << " ~ " << _max << " 사이의 값을 입력해주세요." << std::endl;
			continue;
		}
		else {
			return userInput;
		}
	 }
	return 0;
}