#ifndef DATE_H
#define DATE_H

#include "String.h"

class Date {
	private:
		unsigned short day;
		unsigned short month;
		unsigned short year;

		static bool isValid(unsigned short, unsigned short, unsigned short);
	public:
		static const unsigned short minimumYear;
		static const char componentsDelimiter;
		static const String formatExpected;

		Date(unsigned short day, unsigned short month, unsigned short year);
		Date(const String& date);
		Date(const Date&);
		String toString() const;
};

#endif

