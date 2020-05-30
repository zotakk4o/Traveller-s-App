#ifndef GETFRIENDSEXCURSIONSSCOMMAND_H
#define GETFRIENDSEXCURSIONSSCOMMAND_H

#include "BaseClasses/AppCommandParameters.h"

class GetFriendsExcursionsCommand : public AppCommandParameters {
	public:
		virtual const unsigned short getParametersCount() const;
		virtual ~GetFriendsExcursionsCommand();
		virtual String toString() const;
		virtual void execute(User&, Vector<String>&) const;
};

#endif
