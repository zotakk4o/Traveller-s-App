#ifndef APPHELPCOMMAND_H
#define APPHELPCOMMAND_H

#include "BaseClasses/AppCommand.h"

class AppHelpCommand : public AppCommand {
	public:
		virtual ~AppHelpCommand();
		virtual void execute() const;
		virtual String toString() const;
};
#endif
