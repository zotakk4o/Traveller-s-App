#ifndef DESTINATION_H
#define DESTINATION_H

#include "include/String.h"
#include "User.h"

class Destination {
	private:
		String destination;
		Vector<User> users;
	public:
		Destination();
		Destination(const String&, const Vector<User>&);
		Destination& operator=(const Destination&);

		void addUser(const User&);

		const String& getDestination() const;
		const Vector<User>& getUsers() const;
};

#endif
