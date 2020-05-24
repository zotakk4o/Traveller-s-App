#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "include/String.h"
#include "../models/User.h"

class UserRepository {
	private:
		static Vector<User> mapToUsers(const Vector<String>&);
	public:
		static User getUser(const String&);
		static Vector<User> getAllUsers();
		static Vector<Excursion> getUserExcursions(const User&, const String& = "");
		static Vector<User> selectUsers(const Vector<String>&);	
		static void insertUser(const User&);
		static void deleteUser(const User&);
};

#endif
