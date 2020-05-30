#include "AppConfig.h"
#include <iostream>
#include<conio.h>
#include "../commands/AddExcursionCommand.h"
#include "../commands/AddFriendCommand.h"
#include "../commands/GetExcursionGradeCommand.h"
#include "../commands/GetFriendsExcursionsCommand.h"
#include "../commands/LoginCommand.h"
#include "../commands/RegisterCommand.h"
#include "../commands/RemoveExcursionCommand.h"
#include "../commands/RemoveFriendCommand.h"
#include "../commands/AppExitCommand.h"

const String AppConfig::cancelCommand = "cancel";

std::istream& AppConfig::inputStream = std::cin;

const char AppConfig::commandDelimiter = ' ';

const String AppConfig::defaultFilesLocation = "db-files/";

const String AppConfig::dbFileExtension = ".db";

ConsoleLogger& AppConfig::consoleLogger = ConsoleLogger::getInstance();

const Vector<String> AppConfig::allowedImageExtensions = {".jpeg", "png"};

const Vector<unsigned short> AppConfig::gradeBoundaries = {1, 5};

const char AppConfig::vectorValuesDelimiter = '|';

const char AppConfig::fileDelimiter = '\t';

const Vector<String> AppConfig::bannedStrings = { AppConfig::fileDelimiter, AppConfig::vectorValuesDelimiter, "shit", "fuck" }; // the first element is not an empty space, used for text filtering

FileLogger AppConfig::fileLogger{"logs/app.log"};

DBFile AppConfig::mainDB{&AppConfig::fileLogger, AppConfig::defaultFilesLocation + "application.db", true};

const String AppConfig::usersTable = "users";
const String AppConfig::friendshipsTable = "friendships";
const String AppConfig::destinationsTable = "destinations";

const Vector<String> AppConfig::excursionTableConfig = {
	"destination", "STRING",
	"firstDate", "STRING",
	"secondDate", "STRING",
	"grade", "DOUBLE",
	"comment", "STRING",
	"photos", "STRING"
};

const LoginCommand* AppConfig::loginCommand = new LoginCommand();

const Vector<AppCommand*> AppConfig::appCommands{
	new AppExitCommand(),
	new RegisterCommand()
};

const Vector<AppCommandParameters*> AppConfig::appCommandsParameters{
	new AddFriendCommand(),
	new AddExcursionCommand(),
	new RemoveFriendCommand()
};

bool AppConfig::isTextValid(const String& text, const Vector<String>& allowedSpecialSymbols, const Vector<String>& userBannedStrings) {
	if (AppConfig::areBannedFound(text)) {
		return false;
	}

	unsigned int userBannedStringsSize = userBannedStrings.getSize();
	for (unsigned int i = 0; i < userBannedStringsSize; i++)
	{
		if (text.indexOf(userBannedStrings[i]) != -1) {
			return false;
		}
	}

	unsigned int textSize = text.getLength();
	for (unsigned int i = 0; i < textSize; i++)
	{
		if ((i == 0 || i == textSize - 1) && allowedSpecialSymbols.indexOf(text[i]) != -1) {
			return false;
		}

		if ((text[i] < 'a' || text[i] > 'z') &&
			(text[i] < 'A' || text[i] > 'Z') &&
			(text[i] < '0' || text[i] > '9') &&
			allowedSpecialSymbols.indexOf(text[i]) == -1) {
			return false;
		}
	}

	return true;
}

bool AppConfig::areBannedFound(const String& text) {
	unsigned int bannedSize = AppConfig::bannedStrings.getSize();
	for (unsigned int i = 0; i < bannedSize; i++)
	{
		if (text.indexOf(AppConfig::bannedStrings[i]) != -1) {
			return true;
		}
	}

	return false;
}

void AppConfig::readPassword(String& command) {
	char character;
	while (true) {
		character = _getch();

		if (character == '\n' || character == '\r\n' || character == '\r') {
			_putch('\n');
			break;
		}

		if (character != '\b') {
			_putch('*');
			command += character;
		}
		else {
			if (command.getLength()) {
				command = command.substring(0, command.getLength() - 1);
			}	
		}
	}
}

AppConfig::~AppConfig() {
	delete AppConfig::loginCommand;

	unsigned int appCommandsSize = AppConfig::appCommands.getSize();
	for (unsigned int i = 0; i < appCommandsSize; i++)
	{
		delete AppConfig::appCommands[i];
	}

	unsigned int appCommandsParametersSize = AppConfig::appCommandsParameters.getSize();
	for (unsigned int i = 0; i < appCommandsParametersSize; i++)
	{
		delete AppConfig::appCommandsParameters[i];
	}
}