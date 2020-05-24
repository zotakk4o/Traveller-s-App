#ifndef APPCONFIG_H
#define APPCONFIG_H

#include "include/String.h"
#include "include/Loggers/ConsoleLogger.h"
#include "include/Loggers/FileLogger.h"

class AppConfig {
	public:
		static const String defaultFilesLocation;
		static const char vectorValuesDelimiter;
		static const Vector<String> bannedStrings;
		static const Vector<String> allowedImageExtensions;
		static const Vector<unsigned short> gradeBoundaries;
		static const ConsoleLogger& consoleLogger;
		static FileLogger fileLogger;

		static bool isTextValid(const String& name, const Vector<String>& allowedSpecialSymbols = {}, const Vector<String>& userBannedStrings = {});
		static bool areBannedFound(const String&);
};

#endif
