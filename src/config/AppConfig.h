#ifndef APPCONFIG_H
#define APPCONFIG_H

#include "include/String.h"
#include "include/Loggers/ConsoleLogger.h"
#include "include/Loggers/FileLogger.h"

class AppConfig {
	public:
		static const String defaultFilesLocation;
		static const ConsoleLogger& consoleLogger;
		static FileLogger fileLogger;
};

#endif
