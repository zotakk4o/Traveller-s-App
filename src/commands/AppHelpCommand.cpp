#include "AppHelpCommand.h"

#include "../config/AppConfig.h"

AppHelpCommand::~AppHelpCommand() {}

void AppHelpCommand::execute() const {
	AppConfig::consoleLogger.log("register					starts a registration dialog");
	AppConfig::consoleLogger.log("login						starts a login dialog");
	AppConfig::consoleLogger.log("add friend <username>				adds a friendship with <username>");
	AppConfig::consoleLogger.log("remove friend <username>			removes a friendship with <username>");
	AppConfig::consoleLogger.log("add excursion <destination>			starts a dialog for rating a destination");
	AppConfig::consoleLogger.log("remove excursion <destination>			removes a destination from your excursions list");
	AppConfig::consoleLogger.log("get destination grade <destination>		prints other users' reviews for the provided destination");
	AppConfig::consoleLogger.log("get friend grade <username>			prints a friend's excursions list");
	AppConfig::consoleLogger.log("exit						closses the application");
	AppConfig::consoleLogger.log("help						prints this message");
}
String AppHelpCommand::toString() const {
	return "help";
}
