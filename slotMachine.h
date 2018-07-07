#pragma once
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;

class slotMachine		// Thanks for checking this out. If you have any ideas/questions
{						// feel free to email me at jenkinsb1@spu.edu
public:
	bool haveWon;

	void obtainInput(bool input);
	void runMachine();
	void exit();

	void distinguish();
	void setResult(bool r);
	bool getResult();

	void createTop();
	void createBottom();

	void topSlotLeft(int selector);
	void topMidSlotLeft(int selector);
	void bottomMidSlotLeft(int selector);
	void bottomSlotLeft(int selector);

	void topSlotMid(int selector);
	void topMidSlotMid(int selector);
	void bottomMidSlotMid(int selector);
	void bottomSlotMid(int selector);

	void topSlotRight(int selector);
	void topMidSlotRight(int selector);
	void bottomMidSlotRight(int selector);
	void bottomSlotRight(int selector);

	void topBorder();
	void bottomBorder();

private:
	int numVars = 3;
};

void slotMachine::setResult(bool r)
{
	this->haveWon = r;
}

bool slotMachine::getResult()
{
	return haveWon;
}

void slotMachine::obtainInput(bool input)
{
	/*cout << input << endl;
	
	if (input != "Yes" /*|| input != "yes" ||
		input != "No" || input != "no")
	{
		cout << "I didn't get that, please try again. (Answer only in 'Yes' or 'No')" << endl;
		cin >> input;
		obtainInput(input);
	}

	else if (input == "Yes" || input == "yes") 
		runMachine();

	else
		exit();*/
}

void slotMachine::createTop()
{
	cout << "    _______________________________" << endl;
	cout << "   /                               \\" << endl;
	cout << "  |===___________________________===|" << endl;
}

void slotMachine::createBottom()
{
	cout << "  |===___________________________===|" << endl;
	cout << "  |  /___________________________\\  |" << endl;
	cout << "  |   |                         |   |" << endl;
	cout << " _|    \\_______________________/    |_" << endl;
	cout << "(_____________________________________)" << endl;
}

void slotMachine::runMachine()
{
	bool decision, won;
	srand(time(NULL));

	createTop();	// This five-line block of code creates the slot machine
	distinguish();
	distinguish();
	distinguish();
	createBottom();

	cout << endl;
	/*
	won = getResult();

	if (won)
		cout << "You win! Congratulations!" << endl;
	*/
	cout << "Would you like to run again?" << endl;
	cin >> decision;
	cout << endl;

	if (decision == 1)
	{
		runMachine();
	}
	else 
		exit();
}

void slotMachine::distinguish()
{
	// This is very unorthodox formatting for strings in C++, but bear with me. All this clump of code does
	// is initialize three random numbers which are used as parameters by 12 methods. Each column of four
	// methods output a certain string based on the number. This allows one row of of icons to form.

	int selectorLeft, selectorMid, selectorRight;
	bool result;

	selectorLeft = rand() % numVars + 1;
	selectorMid = rand() % numVars + 1;
	selectorRight = rand() % numVars + 1;
	
	topBorder();				 
	topSlotLeft(selectorLeft);		 topSlotMid(selectorMid);		topSlotRight(selectorRight);
	topMidSlotLeft(selectorLeft);	 topMidSlotMid(selectorMid);	topMidSlotRight(selectorRight);
	bottomMidSlotLeft(selectorLeft); bottomMidSlotMid(selectorMid); bottomMidSlotRight(selectorRight);
	bottomSlotLeft(selectorLeft);	 bottomSlotMid(selectorMid);	bottomSlotRight(selectorRight);
	bottomBorder();	

	/*
	if (selectorLeft == selectorMid && selectorMid == selectorRight)
	{
		result = true;
		setResult(result);
	}
	*/
}

void slotMachine::topSlotLeft(int selector)
{
	if (selector == 1)
	{
		cout << "  || |\\_     | ";
		//cout << "|| \\ _  |";
		//cout << "| \\_(_) |";
		//cout << "| (_)   |";
	}

	else if (selector == 2)
	{
		cout << "  || | _____ | ";
		//cout << "||     ||";
		//cout << "||*BAR*||";
		//cout << "||_____||";
	}

	else if (selector == 3)
	{
		cout << "  || |  ___  | ";
		//cout << "| |_  | |";
		//cout << "|  / /  |";
		//cout << "| /_/   |";
	}
}

void slotMachine::topMidSlotLeft(int selector)
{
	if (selector == 1)
	{
		//cout << "|\\_     | ";
		cout << "  || || \\ _  | ";
		//cout << "| \\_(_) |";
		//cout << "| (_)   |";
	}

	else if (selector == 2)
	{
		//cout << "| _____ |";
		cout << "  || ||     || ";
		//cout << "||*BAR*||";
		//cout << "||_____||";
	}

	else if (selector == 3)
	{
		//cout << "|  ___  |";
		cout << "  || | |_  | | ";
		//cout << "|  / /  |";
		//cout << "| /_/   |";
	}
}

void slotMachine::bottomMidSlotLeft(int selector)
{
	if (selector == 1)
	{
		//cout << "|\\_     | ";
		//cout << "|| \\ _  |";
		cout << "  || | \\_(_) | ";
		//cout << "| (_)   |";
	}

	else if (selector == 2)
	{
		//cout << "| _____ |";
		//cout << "||     ||";
		cout << "  || ||*BAR*|| ";
		//cout << "||_____||";
	}

	else if (selector == 3)
	{
		//cout << "|  ___  |";
		//cout << "| |_  | |"; 
		cout << "  || |  / /  | ";
		//cout << "| /_/   |"; 
	}
}

void slotMachine::bottomSlotLeft(int selector)
{
	if (selector == 1)
	{
		//cout << "|\\_     | ";
		//cout << "|| \\ _  | ";
		//cout << "| \\_(_) | ";
		cout << "  || | (_)   | ";
	}

	else if (selector == 2)
	{
		//cout << "| _____ | ";
		//cout << "||     || ";
		//cout << "||*BAR*|| ";
		cout << "  || ||_____|| ";
	}

	else if (selector == 3)
	{
		//cout << "|  ___  | ";
		//cout << "| |_  | | ";
		//cout << "|  / /  | "; 
		cout << "  || | /_/   | ";
	}
}

void slotMachine::topSlotMid(int selector)
{
	if (selector == 1)
	{
		cout << "|\\_     | ";
		//cout << "|| \\ _  |";
		//cout << "| \\_(_) |";
		//cout << "| (_)   |";
	}

	else if (selector == 2)
	{
		cout << "| _____ | ";
		//cout << "||     ||";
		//cout << "||*BAR*||";
		//cout << "||_____||";
	}

	else if (selector == 3)
	{
		cout << "|  ___  | ";
		//cout << "| |_  | |";
		//cout << "|  / /  |";
		//cout << "| /_/   |";
	}
}

void slotMachine::topMidSlotMid(int selector)
{
	if (selector == 1)
	{
		//cout << "|\\_     | ";
		cout << "|| \\ _  | ";
		//cout << "| \\_(_) |";
		//cout << "| (_)   |";
	}

	else if (selector == 2)
	{
		//cout << "| _____ |";
		cout << "||     || ";
		//cout << "||*BAR*||";
		//cout << "||_____||";
	}

	else if (selector == 3)
	{
		//cout << "|  ___  |";
		cout << "| |_  | | ";
		//cout << "|  / /  |";
		//cout << "| /_/   |";
	}
}

void slotMachine::bottomMidSlotMid(int selector)
{
	if (selector == 1)
	{
		//cout << "|\\_     | ";
		//cout << "|| \\ _  |";
		cout << "| \\_(_) | ";
		//cout << "| (_)   |";
	}

	else if (selector == 2)
	{
		//cout << "| _____ |";
		//cout << "||     ||";
		cout << "||*BAR*|| ";
		//cout << "||_____||";
	}

	else if (selector == 3)
	{
		//cout << "|  ___  |";
		//cout << "| |_  | |"; 
		cout << "|  / /  | ";
		//cout << "| /_/   |"; 
	}
}

void slotMachine::bottomSlotMid(int selector)
{
	if (selector == 1)
	{
		//cout << "|\\_     | ";
		//cout << "|| \\ _  | ";
		//cout << "| \\_(_) | ";
		cout << "| (_)   | ";
	}

	else if (selector == 2)
	{
		//cout << "| _____ | ";
		//cout << "||     || ";
		//cout << "||*BAR*|| ";
		cout << "||_____|| ";
	}

	else if (selector == 3)
	{
		//cout << "|  ___  | ";
		//cout << "| |_  | | ";
		//cout << "|  / /  | "; 
		cout << "| /_/   | ";
	}
}

void slotMachine::topSlotRight(int selector)
{
	if (selector == 1)
	{
		cout << "|\\_     | ||  " << endl;
		//cout << "|| \\ _  |" << endl;
		//cout << "| \\_(_) |" << endl;
		//cout << "| (_)   |" << endl;
	}

	else if (selector == 2)
	{
		cout << "| _____ | ||  " << endl;
		//cout << "||     ||" << endl;
		//cout << "||*BAR*||" << endl;
		//cout << "||_____||" << endl;
	}

	else if (selector == 3)
	{
		cout << "|  ___  | ||  " << endl;
		//cout << "| |_  | |" << endl;
		//cout << "|  / /  |" << endl;
		//cout << "| /_/   |" << endl;
	}
}

void slotMachine::topMidSlotRight(int selector)
{
	if (selector == 1)
	{
		//cout << "|\\_     | " << endl;
		cout << "|| \\ _  | ||  " << endl;
		//cout << "| \\_(_) |" << endl;
		//cout << "| (_)   |" << endl;
	}

	else if (selector == 2)
	{
		//cout << "| _____ |" << endl;
		cout << "||     || ||  " << endl;
		//cout << "||*BAR*||" << endl;
		//cout << "||_____||" << endl;
	}

	else if (selector == 3)
	{
		//cout << "|  ___  |" << endl;
		cout << "| |_  | | ||  " << endl;
		//cout << "|  / /  |" << endl;
		//cout << "| /_/   |" << endl;
	}
}

void slotMachine::bottomMidSlotRight(int selector)
{
	if (selector == 1)
	{
		//cout << "|\\_     | " << endl;
		//cout << "|| \\ _  |" << endl;
		cout << "| \\_(_) | ||  " << endl;
		//cout << "| (_)   |" << endl;
	}

	else if (selector == 2)
	{
		//cout << "| _____ |" << endl;
		//cout << "||     ||" << endl;
		cout << "||*BAR*|| ||  " << endl;
		//cout << "||_____||" << endl;
	}

	else if (selector == 3)
	{
		//cout << "|  ___  |" << endl;
		//cout << "| |_  | |" << endl;
		cout << "|  / /  | ||  " << endl;
		//cout << "| /_/   |" << endl;
	}
}

void slotMachine::bottomSlotRight(int selector)
{
	if (selector == 1)
	{
		//cout << "|\\_     | " << endl;
		//cout << "|| \\ _  |" << endl;
		//cout << "| \\_(_) |" << endl;
		cout << "| (_)   | ||  " << endl;
	}

	else if (selector == 2)
	{
		//cout << "| _____ |" << endl;
		//cout << "||     ||" << endl;
		//cout << "||*BAR*||" << endl;
		cout << "||_____|| ||  " << endl;
	}

	else if (selector == 3)
	{
		//cout << "|  ___  |" << endl;
		//cout << "| |_  | |" << endl;
		//cout << "|  / /  |" << endl;
		cout << "| /_/   | ||  " << endl;
	}
}

void slotMachine::topBorder()
{
	cout << "  ||  _______   _______   _______  ||" << endl;
}

void slotMachine::bottomBorder()
{
	cout << "  || |_______| |_______| |_______| ||" << endl;
}

void slotMachine::exit()
{
	cout << "Goodbye!" << endl;
}