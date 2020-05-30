#include "AppCommandParameters.h"

AppCommandParameters::~AppCommandParameters() {}

bool AppCommandParameters::isValid(const Vector<String>& keywords) const {
	if (keywords.getSize() != this->getParametersCount()) {
		return false;
	}

	Vector<String> required = this->toString().split(' ');

	unsigned int requiredSize = required.getSize();
	for (unsigned int i = 0; i < requiredSize; i++)
	{
		if (required[i] != keywords[i]) {
			return false;
		}
	}

	return true;
}