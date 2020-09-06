#include "StringCheck.h"
#include <windows.h>

struct myComplex
{
	float x;
	float y;

	myComplex operator+ (const myComplex &a)
	{
		myComplex result;
		result.x = this->x + a.x;
		result.y = this->y + a.y;
		return result;
	}
};

myComplex myPow(myComplex &a)
{
	myComplex result;
	result.x = a.x * a.x - a.y * a.y;
	result.y = 2 * a.x * a.y;
	return result;
}

int colourHandler(string &color)
{	
	int result;
	if (color == "blue")
		result = 1;
	else if (color == "green")
		result = 2;
	else if (color == "lightblue")
		result = 3;
	else if (color == "red")
		result = 4;
	else if (color == "purple")
		result = 5;
	else if (color == "orange")
		result = 6;
	else if (color == "white")
		result = 7;
	else if (color == "gray")
		result = 8;
	else if (color == "yellow")
		result = 14;
	else if (color == "brightwhite")
		result = 15;
	else
	{
		cout << "Colour was not recognized, default blue was set!\n";
		result = 1;
	}

	return result;
}

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	cout << "Please enter number of rows (for best result: 40 ): ";
	int number_rows = StringCheck::inputHandling();
	cout << "Please enter number of columns (for best result: 80 ): ";
	int number_columns = StringCheck::inputHandling();
	while (number_columns > 80)
	{
		cout << "\nWARNING: you entered more columns than the standard size of the console (80)!\n";
		cout << "There migth be problems with visialization depending on the screen!\n\n";
		cout << "Do you want to continue anyway or to enter another value for number of columns:\n";
		cout << "Write \"new\" for new value or any other key to continue: ";
		string mychoice = StringCheck::inputWord(false);
		if (mychoice == "new")
		{
			cout << "Please enter number of columns (for best result: 80 ): ";
			number_columns = StringCheck::inputHandling();
		}
		else
		{
			cout << "\n";
			break;
		}
	}
	cout << "Please enter max number of iterations (for best result: min 200 ): ";
	int max_iteration = StringCheck::inputHandling();
	cout << endl;

	char inside = '#';	
	char outside = '*';

	cout << "Would you prefer custom or default characters?\n";
	cout << "Enter C (or c) for custom and you will be able to choose specific characters\n";
	cout << "or enter any other key for default characters: ";
	string choice = StringCheck::inputWord(false);
	if (choice == "C" || choice == "c")
	{		
		cout << endl;
		cout << "Please enter character for points inside the set: ";
		string enteredChar = StringCheck::inputWord(true);
		inside = enteredChar[0];

		cout << "Please enter character for points outside the set: ";
		enteredChar = StringCheck::inputWord(true);
		outside = enteredChar[0];
	}

	cout << endl;
	cout << "Would you prefer custom or default colours?\n";
	cout << "Enter C (or c) for custom and you will be able to choose specific colours\n";
	cout << "or enter any other key for default colours: ";
	string choice2 = StringCheck::inputWord(false);
	int colour_outside = 1;
	int colour_inside = 8;
	if (choice2 == "C" || choice2 == "c")
	{
		cout << "\nAvailable colurs: blue, green, lightblue, red, purple,\n";
		cout << "orange, white, gray, yellow, brightwhite\n\n";

		cout << "Please enter colour for points inside the set: ";
		string enteredColour = StringCheck::inputWord(false);
		colour_inside = colourHandler(enteredColour);

		cout << "Please enter colour for points outside the set: ";
		enteredColour = StringCheck::inputWord(false);
		colour_outside = colourHandler(enteredColour);
	}
	
	for (int row = 0; row < number_rows; ++row)
	{
		for (int column = 0; column < number_columns; ++column)
		{
			myComplex z = { 0, 0 };
			myComplex c = { (float)column * 2 / number_columns - 1.5f, (float)row * 2 / number_rows - 1 };
			int iteration = 0;
			while ((z.x * z.x + z.y * z.y < 2 * 2) && ++iteration < max_iteration)
				z = myPow(z) + c;			
			if (iteration == max_iteration)
			{
				SetConsoleTextAttribute(hConsole, colour_inside);
				cout << inside;				
			}
			else
			{
				SetConsoleTextAttribute(hConsole, colour_outside);
				cout << outside;				
			}
		}
		cout << '\n';
	}

	SetConsoleTextAttribute(hConsole, 7);
	cout << "Press any key to close the program: ";
	int xx;
	cin >> xx;
	return 0;
}
