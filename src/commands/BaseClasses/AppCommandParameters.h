#ifndef APPCOMMANDPARAMETERS_H
#define APPCOMMANDPARAMETERS_H

#include "include/Vector.cpp"
#include "AppCommandValidator.h"
#include "../../models/User.h"

class AppCommandParameters : public AppCommandValidator {
	public:
		virtual ~AppCommandParameters();
		virtual bool isValid(const Vector<String>&) const;
		virtual void execute(User&, Vector<String>&) const = 0;
};

#endif