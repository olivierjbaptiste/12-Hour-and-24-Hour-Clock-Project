#include "Clock.h"
#include <iostream>
#include <string>
#include <Windows.h>


using namespace std;

bool validateMenuChoice(int value, int min, int max) {
	//Validate Menu Choice
   //@param value - minimum
   //@param value - maximum
   //@returns - what is true
	if (min <= value && value <= max) {

		return true;
	}
	return false;
}

void handleInvalidInput(int min, int max) {
	//handle Invalid Input
   //@param void - minimum function
   //@param void - maximum function
	cout << "Entered value is not valid. Valid range is [" << min << "-" << max << "]" << endl;
}

void printMainMenu() {
	//Print Main Menu
   //@param - output 1 - Display Menu
   //@param - output 2 - Update Clock
	//@param - output 3 - Exit Program
	cout << "1 - Display Menu" << endl;
	cout << "2 - Update Clock" << endl;
	cout << "3 - Exit Program" << endl;
}

void printMenu() {
	//Print Menu
	   //@param - output 1 - Add One Hour
	   //@param - output 2 - Add One Minute
		//@param - output 3 - Add One Second
	cout << "1 - Add One Hour " << endl;
	cout << "2 - Add One Minute" << endl;
	cout << "3 - Add One Second" << endl;
}

void printClock(Clock clock) {
	//Print Clock
   //@param - output - get 12 Hour Format
   //@param - output - get 24 Hour Format
	cout << clock.get12HourFormat() << endl;
	cout << clock.get24HourFormat() << endl;
}




int main()
{

	const int MenuchoiceDisplayclock = 1;
	const int MenuchoiceUpdateclock = 2;
	const int MenuchoiceExit = 3;
	const int MenuchoiceAddOneHour = 1;
	const int MenuchoiceAddOneMinute = 2;
	const int MenuchoiceAddOneSecond = 3;



	Clock clock(23, 59, 59);


	bool keepRunning = true;
	//Validate keep Running
   //@param value - true
	do {

		system("cls");


		printClock(clock);

		printMainMenu();

		int userInput;
		cin >> userInput;

		while (validateMenuChoice(userInput, MenuchoiceDisplayclock, MenuchoiceExit) == false) {
			handleInvalidInput(MenuchoiceDisplayclock, MenuchoiceExit);

			cin >> userInput;
		}
		if (userInput == MenuchoiceDisplayclock) {
			clock.addSecond();
		}
		else if (userInput == MenuchoiceUpdateclock) {
			printMenu();

			cin >> userInput;

			while (validateMenuChoice(userInput, MenuchoiceAddOneHour, MenuchoiceAddOneSecond) == false) {
				handleInvalidInput(MenuchoiceAddOneHour, MenuchoiceAddOneSecond);

				cin >> userInput;
			}
			if (userInput == MenuchoiceAddOneHour) {
				clock.addHour();
			}
			else if (userInput == MenuchoiceAddOneMinute) {
				clock.addMinute();
			}
			else {
				clock.addSecond();
			}
		}


		else {
			keepRunning = false;
		}








	} while (keepRunning);



	return 0;
}