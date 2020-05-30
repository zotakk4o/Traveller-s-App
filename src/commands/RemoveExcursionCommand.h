#ifndef REMOVEEXCURSIONCOMMAND_H
#define REMOVEEXCURSIONCOMMAND_H

#include "BaseClasses/AppCommandParameters.h"

class RemoveExcursionCommand : public AppCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~RemoveExcursionCommand();
		virtual String toString() const;
		virtual void execute(User&, const Vector<String>&) const;
};

#endif