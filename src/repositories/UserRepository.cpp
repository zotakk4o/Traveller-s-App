#include "UserRepository.h"
#include "ExcursionRepository.h"
#include "../config/AppConfig.h"

User UserRepository::getUser(const String& username) {
	return UserRepository::mapToUsers(AppConfig::mainDB.selectFromTable({ "username", username, AppConfig::usersTable }))[0];
}

Vector<User> UserRepository::getAllUsers() {
	return UserRepository::mapToUsers(AppConfig::mainDB.getTableWithName(AppConfig::usersTable).getTableData());
}

Vector<Excursion> UserRepository::getUserExcursions(const User& user) {
	ExcursionRepository repo{ user };
	return repo.getAllExcursions();
}

Excursion UserRepository::getUserExcursion(const User& user, const String& destination) {
	ExcursionRepository repo{ user };
	return repo.getExcursion(destination);
}

Vector<User> UserRepository::selectUsers(const Vector<String>& criteria) {
	Vector<String> select = criteria;
	select.pushBack(AppConfig::usersTable);

	return UserRepository::mapToUsers(AppConfig::mainDB.selectFromTable(select));
}

void UserRepository::insertUser(const User& user) {
	AppConfig::mainDB.insertRow({ AppConfig::usersTable, user.getUsername(), user.getEmail(), user.getPassword() });
	AppConfig::mainDB.save();
}

void UserRepository::deleteUser(const User& user) {
	AppConfig::mainDB.deleteFromTable({ AppConfig::usersTable, "username", user.getUsername() });
	AppConfig::mainDB.save();
}

Vector<User> UserRepository::mapToUsers(const Vector<String>& rows) {
	if (!rows.getSize()) {
		return Vector<User>{};
	}

	Vector<User> res;

	unsigned int rowsSize = rows.getSize();
	for (unsigned int i = 0; i < rowsSize; i++)
	{
		Vector<String> data = rows[i].split(AppConfig::fileDelimiter);
		res.pushBack(User{ data[0], data[1], data[2] });
	}

	return res;
}

Vector<String> UserRepository::extractUsernames(const Vector<User>& users) {
	Vector<String> usernames;

	unsigned int usersSize = users.getSize();
	for (unsigned int i = 0; i < usersSize; i++)
	{
		usernames.pushBack(users[i].getUsername());
	}

	return usernames;
}