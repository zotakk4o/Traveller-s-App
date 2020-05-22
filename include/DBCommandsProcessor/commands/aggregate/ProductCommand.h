#ifndef PRODUCTCOMMAND_H
#define PRODUCTCOMMAND_H

#include "BaseClasses/BaseAggregateCommand.h"

class ProductCommand : public BaseAggregateCommand {
public:
	virtual ~ProductCommand();
	virtual String toString() const;
	virtual void execute(const Vector<double>&) const;
};

#endif
