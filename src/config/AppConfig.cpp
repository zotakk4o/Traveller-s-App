#include "AppConfig.h"

const String AppConfig::defaultFilesLocation = "db-files/";

ConsoleLogger& AppConfig::consoleLogger = ConsoleLogger::getInstance();

const Vector<String> AppConfig::allowedImageExtensions = {".jpeg", "png"};

const Vector<unsigned short> AppConfig::gradeBoundaries = {1, 5};

const char AppConfig::vectorValuesDelimiter = '~';

const char AppConfig::fileDelimiter = '⠀';

const Vector<String> AppConfig::bannedStrings = { '⠀', AppConfig::vectorValuesDelimiter, "shit", "fuck" }; // the first element is not an empty space, used for text filtering

FileLogger AppConfig::fileLogger{"logs/app.log"};

DBFile AppConfig::mainDB{&AppConfig::fileLogger, AppConfig::defaultFilesLocation + "application.db", true};

const String AppConfig::usersTable = "users";
const String AppConfig::friendshipsTable = "friendships";

const String AppConfig::excursionTableConfig = "destination-STRING⠀firstDate-STRING⠀secondDate-STRING⠀grade-DOUBLE⠀comment-STRING⠀photos-STRING";

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

		if (text[i] < 'a' && text[i] > 'z' &&
			text[i] < 'A' && text[i] > 'Z' &&
			text[i] < '0' && text[i] > '9' &&
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