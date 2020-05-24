#ifndef DESTINATION_H
#define DESTINATION_H

#include "include/String.h"
#include "User.h"

class Destination {
	private:
		String destination;
		Vector<User> users;
	public:
		void addUser(const User&);
		const Vector<User>& getUsers() const;
};

#endif
