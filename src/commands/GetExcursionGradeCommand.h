#ifndef GETEXCURSIONGRADECOMMAND_H
#define GETEXCURSIONGRADECOMMAND_H

#include "BaseClasses/AppCommandParameters.h"

class GetExcursionGradeCommand : public AppCommandParameters {
	public:
		virtual const unsigned short getParametersCount() const;
		virtual ~GetExcursionGradeCommand();
		virtual String toString() const;
		virtual void execute(User&, Vector<String>&) const;
};

#endif
