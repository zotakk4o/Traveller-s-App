#ifndef USER_H
#define USER_H

#include "include/String.h"
#include "Friendship.h"
#include "include/DBCommandsProcessor/FilesHandlers/DBFile.h"

class User {
	private:
		String username;
		String email;
		String password;

		DBFile db;
	public:
		User(const String& username, const String& email, const String& password);
		String getUsername() const;
		String getEmail() const;

};

#endif

