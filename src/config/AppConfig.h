#ifndef APPCONFIG_H
#define APPCONFIG_H

#include "include/String.h"
#include "include/Loggers/ConsoleLogger.h"
#include "include/Loggers/FileLogger.h"
#include "include/DBCommandsProcessor/FilesHandlers/DBFile.h"
#include "../commands/BaseClasses/AppCommand.h"
#include "../commands/BaseClasses/AppCommandParameters.h"
#include "../commands/LoginCommand.h"

class AppConfig {
	public:
		static const String cancelCommand;
		static const String defaultFilesLocation;
		static const String dbFileExtension;
		static const char vectorValuesDelimiter;
		static const char fileDelimiter;
		static std::istream& inputStream;
		static const char commandDelimiter;
		static const Vector<String> bannedStrings;
		static const Vector<String> allowedImageExtensions;
		static const Vector<unsigned short> gradeBoundaries;
		static ConsoleLogger& consoleLogger;
		static FileLogger fileLogger;
		static DBFile mainDB;
		static const String usersTable;
		static const String friendshipsTable;
		static const Vector<String> excursionTableConfig;
		static const String destinationsTable;
		static const LoginCommand* loginCommand;
		static const Vector<AppCommand*> appCommands;
		static const Vector<AppCommandParameters*> appCommandsParameters;

		static bool isTextValid(const String& name, const Vector<String>& allowedSpecialSymbols = {}, const Vector<String>& userBannedStrings = {});
		static bool areBannedFound(const String&);
		static void readPassword(String&);

		~AppConfig();
};

#endif
