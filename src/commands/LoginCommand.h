#ifndef LOGINCOMMAND_H
#define LOGINCOMMAND_H

#include "BaseClasses/AppCommandValidator.h"
#include "../models/User.h"

class LoginCommand : public AppCommandValidator {
	public:
		virtual const unsigned short getParametersCount() const;
		virtual ~LoginCommand();
		virtual String toString() const;
		User execute() const;
};

#endif