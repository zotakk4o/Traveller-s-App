#include "AppConfig.h"

const ConsoleLogger& AppConfig::consoleLogger = ConsoleLogger::getInstance();
FileLogger AppConfig::fileLogger{"logs/app.log"};