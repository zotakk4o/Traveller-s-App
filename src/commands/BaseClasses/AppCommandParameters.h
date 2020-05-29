#ifndef APPCOMMANDPARAMETERS_H
#define APPCOMMANDPARAMETERS_H

#include "include/Vector.cpp"
#include "AppCommandValidator.h"

class AppCommandParameters : public AppCommandValidator {
	public:
		virtual ~AppCommandParameters();
		virtual void execute(const Vector<String>&) const = 0;
};

#endif