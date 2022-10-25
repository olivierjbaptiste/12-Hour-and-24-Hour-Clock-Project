#include "Clock.h"


Clock::Clock() {
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
}

Clock::Clock(int hours, int minutes, int seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

void Clock::addHour() {
	//Validate Clock
   //@param value - add Hour
	if (hours == 23) {
		hours = 0; //reset to midnight
	}
	else {
		hours++;
	}
}



void Clock::addSecond() {
	//Validate Clock
   //@param value - add Second
	if (seconds == 59) {
		seconds = 0;
		addMinute();
	}
	else {
		seconds++;
	}

}


void Clock::addMinute() {
	//Validate Clock
   //@param value - add Minute
	if (minutes == 59) {
		minutes = 0;
		addHour();
	}
	else {
		minutes++;
	}
}


string Clock::get24HourFormat() {
	return pad(hours) + ":" + pad(minutes) + ":" + pad(seconds);

}

string Clock::get12HourFormat() {
	if (hours == 0) {
		return "12:" + pad(minutes) + ":" + pad(seconds) +"AM";
	}
	else if (hours < 12) {
		return pad(hours) + ":" + pad(minutes) + ":" + pad(seconds) + "AM";

	}
	else if (hours == 12) {
		return pad(hours) + ":" + pad(minutes) + ":" + pad(seconds) + "PM";

	}
	else {
		return pad(hours - 12) + ":" + pad(minutes) + ":" + pad(seconds) + "PM";

	}
	return "";
}

string Clock::pad(int value) {
	if (value < 10) {
		return "0" + to_string(value);
	}
	else {
		return to_string(value);
	}
	

}
