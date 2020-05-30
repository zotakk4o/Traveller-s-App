#ifndef REMOVEFRIENDCOMMAND_H
#define REMOVEFRIENDCOMMAND_H

#include "BaseClasses/AppCommandParameters.h"

class RemoveFriendCommand : public AppCommandParameters {
	public:
		virtual const unsigned short getParametersCount() const;
		virtual ~RemoveFriendCommand();
		virtual String toString() const;
		virtual void execute(User&, Vector<String>&) const;
};

#endif

