#ifndef DELETECOMMAND_H
#define DELETECOMMAND_H

#include "BaseClasses/DBFileCommandParameters.h"

class DeleteCommand : public DBFileCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~DeleteCommand();
		virtual void execute(DBFile&, const Vector<String>&) const;
		virtual String toString() const;
};

#endif
