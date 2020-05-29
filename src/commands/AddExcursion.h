#ifndef ADDEXCURSIONCOMMAND_H
#define ADDEXCURSIONCOMMAND_H

#include "BaseClasses/AppCommandParameters.h"

class AddExcursion : public AppCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~AddExcursion();
		virtual bool isValid(const Vector<String>&) const;
		virtual String toString() const;
		virtual void execute(const Vector<String>&) const;
};

#endif