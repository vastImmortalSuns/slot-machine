#include "stdafx.h"
#include <iostream>
#include "slotMachine.h"

using namespace std;

int main()
{
	slotMachine luckyMachine;
	bool input;

	cout << "Do you want to try your luck? If so, enter 1. If not, enter 0." << endl;
	cin >> input;

	luckyMachine.runMachine();
    return 0;
}

