#ifndef ADDFRIENDCOMMAND_H
#define ADDFRIENDCOMMAND_H

#include "BaseClasses/AppCommandParameters.h"

class AddFriendCommand : public AppCommandParameters {
	public:
		virtual const unsigned short getParametersCount() const;
		virtual ~AddFriendCommand();
		virtual String toString() const;
		virtual void execute(User&, Vector<String>&) const;
};

#endif

