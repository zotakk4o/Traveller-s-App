#ifndef APPEXITCOMMAND_H
#define APPEXITCOMMAND_H

#include "BaseClasses/AppCommand.h"

class AppExitCommand :	public AppCommand {
	public:
		virtual ~AppExitCommand();
		virtual void execute() const;
		virtual String toString() const;
};
#endif
