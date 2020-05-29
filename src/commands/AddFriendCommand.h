#ifndef ADDFRIENDCOMMAND_H
#define ADDFRIENDCOMMAND_H

#include "BaseClasses/AppCommandParameters.h"

class AddFriendCommand : public AppCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~AddFriendCommand();
		virtual bool isValid(const Vector<String>&) const;
		virtual String toString() const;
		virtual void execute(const Vector<String>&) const;
};

#endif

