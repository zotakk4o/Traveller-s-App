#ifndef APPCOMMAND_H
#define APPCOMMAND_H

#include "include/String.h"
#include "AppCommandValidator.h"

class AppCommand : public AppCommandValidator {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~AppCommand();
		virtual void execute() const = 0;
};

#endif

