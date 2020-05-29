#include "RegisterCommand.h"
#include "../repositories/UserRepository.h"
#include "../config/AppConfig.h"
#include "../config/AppMessages.h"
#include "../config/AppErrors.h"

RegisterCommand::~RegisterCommand() {}

String RegisterCommand::toString() const {
	return "register";
}

void RegisterCommand::execute() const {
	String currCommand;
	String username;
	String email;
	String password;

	while (true) {
		//Username Check
		AppConfig::consoleLogger.log(AppMessages::enterUsernameMessage);
		String::getLine(AppConfig::inputStream, currCommand);

		if (currCommand == AppConfig::cancelCommand) {
			AppConfig::consoleLogger.log(AppMessages::registrationCancelledMessage);
			return;
		}

		try
		{
			User{ currCommand, "valid@email.com", "validPassword" };
			username = currCommand;
		}
		catch (const String & err)
		{
			AppConfig::consoleLogger.log(err);
			continue;
		}

		//Email Check
		AppConfig::consoleLogger.log(AppMessages::enterEmailMessage);
		String::getLine(AppConfig::inputStream, currCommand);

		if (currCommand == AppConfig::cancelCommand) {
			AppConfig::consoleLogger.log(AppMessages::registrationCancelledMessage);
			return;
		}

		try
		{
			User{ "validUsername", currCommand, "validPassword" };
			email = currCommand;
		}
		catch (const String & err)
		{
			AppConfig::consoleLogger.log(err);
			continue;
		}

		//Password Check
		AppConfig::consoleLogger.log(AppMessages::enterPasswordMessage);

		currCommand = "";
		AppConfig::readPassword(currCommand);

		if (currCommand == AppConfig::cancelCommand) {
			AppConfig::consoleLogger.log(AppMessages::registrationCancelledMessage);
			return;
		}

		try
		{
			User{ "validUsername", "valid@email.com", currCommand };
			password = currCommand;
		}
		catch (const String & err)
		{
			AppConfig::consoleLogger.log(err);
			continue;
		}

		break;
	}

	User newUser{ username, email, password };

	if (UserRepository::getUser(username).getUsername() == username) {
		throw AppErrors::userAlreadyExists;
	}

	UserRepository::insertUser(newUser);
	AppConfig::consoleLogger.log(AppMessages::successfulRegistrationMessage);
}
