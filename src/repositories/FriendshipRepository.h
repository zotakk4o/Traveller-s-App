#ifndef FRIENDSHIPREPOSITORY_H
#define FRIENDSHIPREPOSITORY_H

#include "include/String.h"
#include "../models/User.h"

class FriendshipRepository {
	private:
		static const String tableName;
	public:
		Vector<User> selectFriendships(const User&);
		void insertFriendship(const User&, const User&);
		void deleteFriendship(const User&);
};

#endif
