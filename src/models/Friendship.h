#ifndef FRIENDSHIP_H
#define FRIENDSHIP_H

#include "include/String.h"

class User;

class Friendship {
	private:
		static const String tableName;
		String currentUsername;
		String otherUsername;
	public:
		Friendship(const String&, const String&);
		User getOtherUser();
};

#endif