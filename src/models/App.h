#ifndef APP_H
#define APP_H

#include "src/models/User.h"
#include "include/Vector.h"

class App {
	private:
		static const String tableName;
		Vector<User> users;
	public:
		App();

		void addUser(const User&);
};

#endif

