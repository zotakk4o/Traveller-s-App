#include "AppCommandsProcessor.h"
#include "config/AppConfig.h"
#include "config/AppErrors.h"

void AppCommandsProcessor::parseCommands() {
	String command;
	User loggedIn;
	while (true)
	{
		String::getLine(AppConfig::inputStream, command);
		try {
			if (!this->parseAppCommand(command, loggedIn)) {
				AppConfig::consoleLogger.log(AppErrors::wrongCommandError);
			}
		}
		catch (const String& err) {
			AppConfig::consoleLogger.log(err);
		}
		
	}
}

bool AppCommandsProcessor::parseAppCommand(const String& command, User& loggedIn) {
	Vector<String> keywords = command.split(AppConfig::commandDelimiter);

	if (AppConfig::loginCommand->isValid(keywords) && !loggedIn.getUsername().getLength()) {
		User loginUser = AppConfig::loginCommand->execute();
		if (loginUser.getUsername().getLength()) {
			loggedIn = loginUser;
		}
		return true;
	}

	unsigned int appCommandsSize = AppConfig::appCommands.getSize();
	for (unsigned int i = 0; i < appCommandsSize; i++)
	{
		if (AppConfig::appCommands[i]->isValid(keywords)) {
			AppConfig::appCommands[i]->execute();
			return true;
		}
	}

	if (keywords.getSize() < 2 || !loggedIn.getUsername().getLength()) {
		return false;
	}

	unsigned int appCommandsParametersSize = AppConfig::appCommandsParameters.getSize();
	for (unsigned int i = 0; i < appCommandsParametersSize; i++) {
		if (AppConfig::appCommandsParameters[i]->isValid(keywords)) {
			Vector<String> parameters = keywords.slice(
				AppConfig::appCommandsParameters[i]->toString().split(' ').getSize(),
				keywords.getSize() - 1
			);
			AppConfig::appCommandsParameters[i]->execute(loggedIn, parameters);
			return true;
		}
	}

	return false;
}

void AppCommandsProcessor::start() {
	this->parseCommands();
}