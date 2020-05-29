#ifndef REMOVEEXCURSIONCOMMAND_H
#define REMOVEEXCURSIONCOMMAND_H

#include "BaseClasses/AppCommandParameters.h"

class RemoveExcursion : public AppCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~RemoveExcursion();
		virtual bool isValid(const Vector<String>&) const;
		virtual String toString() const;
		virtual void execute(const Vector<String>&) const;
};

#endif