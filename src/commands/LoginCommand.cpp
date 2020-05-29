#include "LoginCommand.h"

#include "../repositories/UserRepository.h"
#include "../config/AppConfig.h"
#include "../config/AppMessages.h"
#include "../config/AppErrors.h"

LoginCommand::~LoginCommand() {}

const unsigned short LoginCommand::getParametersCount() const {
	return 1;
}

String LoginCommand::toString() const {
	return "login";
}

User LoginCommand::execute() const {
	String currCommand;
	String username;
	String password;

	while (true) {
		AppConfig::consoleLogger.log(AppMessages::enterUsernameMessage);
		String::getLine(AppConfig::inputStream, currCommand);

		if (currCommand == AppConfig::cancelCommand) {
			AppConfig::consoleLogger.log(AppMessages::loginCancelledMessage);
			return User{};
		}

		username = currCommand;

		AppConfig::consoleLogger.log(AppMessages::enterPasswordMessage);

		currCommand = "";
		AppConfig::readPassword(currCommand);

		if (currCommand == AppConfig::cancelCommand) {
			AppConfig::consoleLogger.log(AppMessages::loginCancelledMessage);
			return User{};
		}

		password = currCommand;

		User res = UserRepository::getUser(username);

		if (res.getUsername() != username || !res.arePasswordsTheSame(password)) {
			AppConfig::consoleLogger.log(AppMessages::userMissmatchMessage);
			continue;
		}

		AppConfig::consoleLogger.log(AppMessages::successfulLoginMessage + res.getUsername());
		return res;
	}
}
