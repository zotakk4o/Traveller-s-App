#ifndef FRIENDSHIPREPOSITORY_H
#define FRIENDSHIPREPOSITORY_H

#include "include/String.h"
#include "../models/User.h"

class FriendshipRepository {
	private:
		static Vector<User> mapToFriends(const String& curreUsername, const Vector<String>&);
	public:
		static bool areFriends(const User&, const User&);
		static Vector<User> selectFriendships(const User&);
		static void insertFriendship(const User&, const User&);
		static void deleteFriendship(const User&);
};

#endif
