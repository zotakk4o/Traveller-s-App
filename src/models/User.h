#ifndef USER_H
#define USER_H

#include "include/String.h"
#include "Friendship.h"
#include "Excursion.h"
#include "include/DBCommandsProcessor/FilesHandlers/DBFile.h"

class User {
	private:
		static const unsigned short minPasswordLength;
		static const unsigned short maxUsernameLegnth;
		String username;
		String email;
		String password;

		Vector<Excursion> excursions;
		Vector<Friendship> friends; //I have no friends :(

		bool isEmailValid(const String&) const;
		bool arePasswordsTheSame(const String&) const;
		String hashPassword(const String&) const;
	public:
		User();
		User(const String& username, const String& email, const String& password);
		User& operator=(const User&);

		void addFriend(const User&);
		void addExcursion(const Excursion&);

		String getUsername() const;
		String getEmail() const;
		Vector<Excursion> getAllExcursions() const;
};

#endif

