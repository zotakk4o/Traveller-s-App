#include "User.h"
#include "../config/AppErrors.h"
#include "../config/AppConfig.h"

const unsigned short User::maxUsernameLegnth = 50;
const unsigned short User::minPasswordLength = 5;
User::User() {}

User::User(const String& username, const String& email, const String& password) {
	if (!AppConfig::isTextValid(username) && username.indexOf(' ') != -1 || username.getLength() > User::maxUsernameLegnth) {
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

void User::addExcursion(const Excursion& excursion) {
	this->excursions.pushBack(excursion);
}

const String& User::getUsername() const {
	return this->username;
}

const String& User::getEmail() const {
	return this->email;
}

const String& User::getPassword() const {
	return this->password;
}

const Vector<Excursion>& User::getAllExcursions() const {
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

	return AppConfig::isTextValid(email, { '-', '.', '_' });
}

String User::hashPassword(const String& password) const {
	unsigned short precision = 2;
	return String::toString((*(unsigned long long*)password.getConstChar()) >> precision);
}

const Excursion& User::getExcursion(const String& destination) const {
	unsigned int excursionsSize = this->excursions.getSize();
	for (unsigned i = 0; i < excursionsSize; i++)
	{
		if (this->excursions[i].getDestination() == destination) {
			return this->excursions[i];
		}
	}

	throw AppErrors::noDestinationFoundError;
}