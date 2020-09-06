#pragma once
#include <iostream>
#include <string>

using namespace std;

class StringCheck
{
public:
	static const bool isNumber(string & input);
	static const bool isNotTooBig(const string & strNumber);
	static void removeIntervalsInBeginning(string & input);

	static const string getFirstWord(string & input, bool canBeInterval);
	static const int findNumber(string & input);

	static const int inputHandling();
	static const string inputWord(bool canBeInterval);
};
