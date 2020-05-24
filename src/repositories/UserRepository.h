#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "include/String.h"
#include "../models/User.h"

class UserRepository {
	public:
		User getUser(const String&);
		Vector<User> getAllUsers();
		Vector<Excursion> getUserExcursions(const User&, const String& = "");

		Vector<User> selectUsers(const Vector<String>&);	
		void insertUser(const User&);
		void updateUser(const User&);
		void deleteUser(const User&);
};

#endif
