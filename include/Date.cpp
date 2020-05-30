#include "Date.h"

const unsigned short Date::minimumYear = 1900;
const char Date::componentsDelimiter = '.';
const String Date::formatExpected = "<day>.<month>.<year>";

Date::Date() : day(-1), month(-1), year(-1) {}

Date::Date(unsigned short day, unsigned short month, unsigned short year) {
	if (!Date::isValid(day, month, year)) {
		throw "Error: invalid arguments. Could not create a date from the entered day, month and year.";
	}

	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(const String& date) {
	String invalidDateErr = "Error: invalid arguments. Could not create a date from the entered string.";
	Vector<String> components = date.split(Date::componentsDelimiter);

	if (components.getSize() != 3 || String::isNumeric(components[0]) != 0 || String::isNumeric(components[1]) != 0 || String::isNumeric(components[2]) != 0) {
		throw invalidDateErr.getConstChar();
	}
	
	unsigned short day = String::toInt(components[0]);
	unsigned short month = String::toInt(components[1]);
	unsigned short year = String::toInt(components[2]);


	if (!Date::isValid(day, month, year)) {
		throw invalidDateErr.getConstChar();
	}

	this->day = day;
	this->month = month;
	this->year = year;
}

String Date::toString() const {
	String res;

	if (this->day < 10) {
		res += '0';
	}

	res += String::toString(this->day) + Date::componentsDelimiter;;

	if (this->month < 10) {
		res += '0';
	}

	res += String::toString(this->month) + Date::componentsDelimiter;

	res += String::toString(this->year);

	return res;
}

bool Date::isValid(unsigned short day, unsigned short month, unsigned short year) {
	unsigned short febDays = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) ? 29 : 28;
	Vector<unsigned short> daysPerMonth = {0, 31, febDays, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return (month >= 1 && month <= 12) && (day >= 1 && day <= daysPerMonth[month]) && (year >= Date::minimumYear);
}

bool Date::isDateValid() const {
	return this->isValid(this->day, this->month, this->year);
}

bool Date::operator>(const Date& other) const {
	if (this->year > other.year) {
		return true;
	}

	if (other.year > this->year) {
		return false;
	}

	if (this->month > other.month) {
		return true;
	}

	if (other.month > this->month) {
		return false;
	}

	return this->day > other.day;
}