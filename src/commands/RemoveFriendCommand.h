#ifndef REMOVEFRIENDCOMMAND_H
#define REMOVEFRIENDCOMMAND_H

#include "BaseClasses/AppCommandParameters.h"

class RemoveFriendCommand : public AppCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~RemoveFriendCommand();
		virtual String toString() const;
		virtual void execute(User&, const Vector<String>&) const;
};

#endif

