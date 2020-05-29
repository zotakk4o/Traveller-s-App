#include "Destination.h"

Destination::Destination() {}

Destination::Destination(const String& _destination, const Vector<User>& _users) : destination(_destination), users(_users) {}

Destination& Destination::operator=(const Destination& other) {
	if (this != &other) {
		this->destination = other.destination;
		this->users = other.users;
	}

	return *this;
}

void Destination::addUser(const User& user) {
	this->users.pushBack(user);
}

const Vector<User>& Destination::getUsers() const {
	return this->users;
}

const String& Destination::getDestination() const {
	return this->destination;
}