#ifndef SELECTCOMMAND_H
#define SELECTCOMMAND_H

#include "BaseClasses/DBFileCommandParameters.h"

class SelectCommand : public DBFileCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~SelectCommand();
		virtual bool isValid(const Vector<String>&) const;
		virtual void execute(DBFile&, const Vector<String>&) const;
		virtual String toString() const;
};

#endif