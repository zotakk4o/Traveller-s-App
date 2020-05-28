#include "SelectCommand.h"
SelectCommand::~SelectCommand() {}

const unsigned short SelectCommand::getParametersCount() const {
	return 4;
}

bool SelectCommand::isValid(const Vector<String>& keywords) const {
	return keywords.getSize() >= this->getParametersCount()
		&& keywords.getSize() % 2 == 0
		&& keywords[0] == this->toString();
}

void SelectCommand::execute(DBFile& dbFile, const Vector<String>& parameters) const {
	dbFile.selectFromTable(parameters);
}

String SelectCommand::toString() const {
	return "select";
}