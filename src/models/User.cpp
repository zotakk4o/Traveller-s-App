#include "User.h"
#include "../config/AppErrors.h"

const unsigned short User::maxUsernameLegnth = 50;
const unsigned short User::minPasswordLength = 5;
User::User() {}

User::User(const String& username, const String& email, const String& password) {
	if (username.indexOf(' ') != -1 || username.getLength() > User::maxUsernameLegnth) {
		throw AppErrors::invalidUsernameError;
	}

	if (!this->isEmailValid(email)) {
		throw AppErrors::invalidEmailError;
	}

	if (password.getLength() < User::minPasswordLength) {
		throw AppErrors::invalidPasswordError;
	}

	this->username = username;
	this->email = email;
	this->password = this->hashPassword(password);
}

User& User::operator=(const User& other) {
	if (this == &other) {
		return *this;
	}

	if (!other.username.getLength()) {
		throw AppErrors::invalidUsernameError;
	}

	this->username = other.username;
	this->email = other.email;
	this->password;

	return *this;
}

void User::addFriend(const User& other) {

}

void User::addExcursion(const Excursion&) {

}

String User::getUsername() const {
	return this->username;
}

String User::getEmail() const {
	return this->email;
}

Vector<Excursion> User::getAllExcursions() const {
	return this->excursions;
}

bool User::arePasswordsTheSame(const String& pass) const {
	return this->password == this->hashPassword(pass);
}

bool User::isEmailValid(const String& email) const {
	int atIndex = email.indexOf('@');
	
	if (atIndex == -1 || atIndex == 0 || atIndex == email.getLength() - 1) {
		return false;
	}

	Vector<String> allowedSpecialSymbols = { '-', '.', '_' };

	unsigned int emailSize = email.getLength();
	for (unsigned int i = 0; i < emailSize; i++)
	{
		if ((i == 0 || i == emailSize - 1) && allowedSpecialSymbols.indexOf(email[i]) != -1) {
			return false;
		}

		if (email[i] < 'a' && email[i] > 'z' && 
			email[i] < 'A' && email[i] > 'Z' && 
			email[i] < '0' && email[i] > '9' && 
			allowedSpecialSymbols.indexOf(email[i]) == -1) {
			return false;
		}
	}

	return true;
}

String User::hashPassword(const String& password) const {
	unsigned short precision = 2;
	return String::toString((*(unsigned long long*)password.getConstChar()) >> precision);
}