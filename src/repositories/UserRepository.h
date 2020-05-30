#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "include/String.h"
#include "../models/User.h"

class UserRepository {
	private:
		static Vector<User> mapToUsers(const Vector<String>&);
	public:
		static Vector<String> extractUsernames(const Vector<User>&);
		static User getUser(const String&);
		static Vector<User> getAllUsers();
		static Vector<Excursion> getUserExcursions(const User&);
		static Excursion getUserExcursion(const User&, const String&);
		static Vector<User> selectUsers(const Vector<String>&);	
		static void insertUser(const User&, bool = true);
		static void deleteUser(const User&, bool = true);
};

#endif
