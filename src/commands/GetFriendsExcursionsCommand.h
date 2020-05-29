#ifndef GETFRIENDSEXCURSIONSSCOMMAND_H
#define GETFRIENDSEXCURSIONSSCOMMAND_H

#include "BaseClasses/AppCommandParameters.h"

class GetFriendsExcursionsCommand : public AppCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~GetFriendsExcursionsCommand();
		virtual bool isValid(const Vector<String>&) const;
		virtual String toString() const;
		virtual void execute(const Vector<String>&) const;
};

#endif
