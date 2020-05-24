#include "AppConfig.h"

const String AppConfig::defaultFilesLocation = "db-files/";
const ConsoleLogger& AppConfig::consoleLogger = ConsoleLogger::getInstance();
FileLogger AppConfig::fileLogger{"logs/app.log"};