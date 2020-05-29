#include "AppCommandValidator.h"

AppCommandValidator::~AppCommandValidator() {};

bool AppCommandValidator::isValid(const Vector<String>& keywords) const {
	return this->getParametersCount() == keywords.getSize() && this->toString() == keywords[0];
}