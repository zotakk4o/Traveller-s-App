#ifndef GETEXCURSIONGRADECOMMAND_H
#define GETEXCURSIONGRADECOMMAND_H

#include "BaseClasses/AppCommandParameters.h"

class GetExcursionGradeCommand : public AppCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~GetExcursionGradeCommand();
		virtual bool isValid(const Vector<String>&) const;
		virtual String toString() const;
		virtual void execute(const Vector<String>&) const;
};

#endif
