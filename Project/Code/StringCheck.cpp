#include "StringCheck.h"

const int NOT_FOUND = -1;

const bool StringCheck::isNumber(string &input)
{
	if (input[0] == '+')
	{
		input.erase(input.begin());
	}
	else if (input[0] == '-')
	{
		input.erase(input.begin());		
	}
	return (input.find_first_not_of("0123456789") == NOT_FOUND);
}

const bool StringCheck::isNotTooBig(const string &strNumber)
{
	if (strNumber == "")
	{
		return false;
	}

	return (strNumber.size() <= 9);
}

void StringCheck::removeIntervalsInBeginning(string &input)
{
	while (input != "" && input[0] == ' ')
	{
		input.erase(input.begin());
	}
}

const string StringCheck::getFirstWord(string &input, bool canBeInterval)
{
	if (canBeInterval && input != "" && input[0] == ' ')
	{
		string foundWord = " ";
		return foundWord;
	}
	
	removeIntervalsInBeginning(input);
	int position = input.find(" ");
	string foundWord(input, 0, position); // copies the characters before the first ' ';	
	return foundWord;
}

// if possible returns the number from the string returned by getFirstWord;
const int StringCheck::findNumber(string &input)
{
	string strNumber = getFirstWord(input, false);
	int result = NOT_FOUND;
	if (isNumber(strNumber) && isNotTooBig(strNumber))
	{
		result = stoi(strNumber);
	}
	return result;
}

const int StringCheck::inputHandling()
{
	string input;
	int number = -1;
	while (number <= 0)
	{
		getline(cin, input);
		number = findNumber(input);
		if (number <= 0)
			cout << "\nPlease enter positive number!\n";
	}
	return number;
}

const string StringCheck::inputWord(bool canBeInterval)
{
	string input;
	string word = "";
	while (word == "")
	{
		getline(cin, input);
		word = getFirstWord(input, canBeInterval);
		if (word == "")
			cout << "You did not enter anything!\n";
	}
	return word;
}
