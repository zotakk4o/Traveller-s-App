#ifndef APPCONFIG_H
#define APPCONFIG_H

#include "include/String.h"
#include "include/Loggers/ConsoleLogger.h"
#include "include/Loggers/FileLogger.h"
#include "include/DBCommandsProcessor/FilesHandlers/DBFile.h"

class AppConfig {
	public:
		static const String defaultFilesLocation;
		static const char vectorValuesDelimiter;
		static const char fileDelimiter;
		static const Vector<String> bannedStrings;
		static const Vector<String> allowedImageExtensions;
		static const Vector<unsigned short> gradeBoundaries;
		static ConsoleLogger& consoleLogger;
		static FileLogger fileLogger;
		static DBFile mainDB;
		static const String usersTable;
		static const String friendshipsTable;
		static const String excursionTableConfig;

		static bool isTextValid(const String& name, const Vector<String>& allowedSpecialSymbols = {}, const Vector<String>& userBannedStrings = {});
		static bool areBannedFound(const String&);
};

#endif
