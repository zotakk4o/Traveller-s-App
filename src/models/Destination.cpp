#include "Destination.h"

void Destination::addUser(const User& user) {
	this->users.pushBack(user);
}

const Vector<User>& Destination::getUsers() const {
	return this->users;
}