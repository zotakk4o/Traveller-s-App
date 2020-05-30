#ifndef APPCOMMANDVALIDATOR_H
#define APPCOMMANDVALIDATOR_H

#include "include/String.h"
#include "include/Vector.cpp"

class AppCommandValidator
{
	public:
		virtual const unsigned short getParametersCount() const = 0;
		virtual ~AppCommandValidator();
		virtual bool isValid(const Vector<String>&) const;
		virtual String toString() const = 0;
};

#endif
