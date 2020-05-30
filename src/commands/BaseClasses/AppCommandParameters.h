#ifndef APPCOMMANDPARAMETERS_H
#define APPCOMMANDPARAMETERS_H

#include "include/Vector.cpp"
#include "AppCommandValidator.h"
#include "../../models/User.h"

class AppCommandParameters : public AppCommandValidator {
	public:
		virtual ~AppCommandParameters();
		virtual void execute(User&, const Vector<String>&) const = 0;
};

#endif