#include "UserRepository.h"
#include "../config/AppConfig.h"

User UserRepository::getUser(const String& username) {
	return UserRepository::mapToUsers(AppConfig::mainDB.selectFromTable({ "username", username, AppConfig::usersTable }))[0];
}

Vector<User> UserRepository::getAllUsers() {
	return UserRepository::mapToUsers(AppConfig::mainDB.getTableWithName(AppConfig::usersTable).getTableData());
}

Vector<Excursion> UserRepository::getUserExcursions(const User&, const String & = "") {
	//TODO
}

Vector<User> UserRepository::selectUsers(const Vector<String>& criteria) {
	return UserRepository::mapToUsers(AppConfig::mainDB.selectFromTable({ criteria[0], criteria[1], AppConfig::usersTable }));
}

void UserRepository::insertUser(const User& user) {
	AppConfig::mainDB.insertRow({ AppConfig::usersTable, user.getUsername(), user.getEmail(), user.getPassword() });
}

void UserRepository::deleteUser(const User& user) {
	AppConfig::mainDB.deleteFromTable({ AppConfig::usersTable, "username", user.getUsername() });
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