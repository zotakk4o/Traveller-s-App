#ifndef ADDFRIENDCOMMAND_H
#define ADDFRIENDCOMMAND_H

#include "BaseClasses/AppCommandParameters.h"

class AddFriendCommand : public AppCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~AddFriendCommand();
		virtual String toString() const;
		virtual void execute(User&, const Vector<String>&) const;
};

#endif

