#ifndef GETDESTINATIONGRADECOMMAND_H
#define GETDESTINATIONGRADECOMMAND_H

#include "BaseClasses/AppCommandParameters.h"

class GetDestinationGradeCommand : public AppCommandParameters {
	public:
		virtual const unsigned short getParametersCount() const;
		virtual ~GetDestinationGradeCommand();
		virtual String toString() const;
		virtual void execute(User&, Vector<String>&) const;
};

#endif
