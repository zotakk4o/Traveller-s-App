#ifndef APPOMMANDSPROCESSOR_H
#define APPCOMMANDSPROCESSOR_H

#include "include/String.h"
#include "models/User.h"

class AppCommandsProcessor {
	protected:
		void parseCommands();
		bool parseAppCommand(const String&, User&);
	public:
		void start();
};

#endif 
