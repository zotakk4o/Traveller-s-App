#ifndef REMOVEEXCURSIONCOMMAND_H
#define REMOVEEXCURSIONCOMMAND_H

#include "BaseClasses/AppCommandParameters.h"

class RemoveExcursionCommand : public AppCommandParameters {
	public:
		virtual const unsigned short getParametersCount() const;
		virtual ~RemoveExcursionCommand();
		virtual String toString() const;
		virtual void execute(User&, Vector<String>&) const;
};

#endif