#ifndef ADDEXCURSIONCOMMAND_H
#define ADDEXCURSIONCOMMAND_H

#include "BaseClasses/AppCommandParameters.h"

class AddExcursionCommand : public AppCommandParameters {
	public:
		virtual const unsigned short getParametersCount() const;
		virtual ~AddExcursionCommand();
		virtual String toString() const;
		virtual void execute(User&, Vector<String>&) const;
};

#endif