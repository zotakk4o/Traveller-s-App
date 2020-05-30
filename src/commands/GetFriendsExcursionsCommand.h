#ifndef GETFRIENDSEXCURSIONSSCOMMAND_H
#define GETFRIENDSEXCURSIONSSCOMMAND_H

#include "BaseClasses/AppCommandParameters.h"

class GetFriendsExcursionsCommand : public AppCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~GetFriendsExcursionsCommand();
		virtual String toString() const;
		virtual void execute(User&, const Vector<String>&) const;
};

#endif
