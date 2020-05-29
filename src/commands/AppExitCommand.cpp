#include <stdlib.h>
#include "AppExitCommand.h"
#include "../config/AppMessages.h"
#include "../config/AppConfig.h"

AppExitCommand::~AppExitCommand() {};

void AppExitCommand::execute() const {
	AppConfig::consoleLogger.log(AppMessages::exitMessage);
	exit(EXIT_SUCCESS);
}

String AppExitCommand::toString() const {
	return "exit";
}