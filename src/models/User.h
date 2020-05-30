#ifndef USER_H
#define USER_H

#include "include/String.h"
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

		bool isEmailValid(const String&) const;
		String hashPassword(const String&) const;
	public:
		User();
		User(const String& username, const String& email, const String& password, bool withoutHashing = false);
		User& operator=(const User&);

		bool operator==(const User&);

		void addExcursion(const Excursion&);
		void setExcursions(const Vector<Excursion>&);
		const Excursion& getExcursion(const String&) const;

		const String& getUsername() const;
		const String& getEmail() const;
		const String& getPassword() const;
		const Vector<Excursion>& getAllExcursions() const;

		bool arePasswordsTheSame(const String&) const;
};

#endif

