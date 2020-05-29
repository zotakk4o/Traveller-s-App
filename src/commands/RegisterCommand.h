#ifndef REGISTERCOMMAND_H
#define REGISTERCOMMAND_H

#include "BaseClasses/AppCommand.h"

class RegisterCommand : public AppCommand {
	public:
		virtual String toString() const;
		virtual void execute() const;
		virtual ~RegisterCommand();
};

#endif