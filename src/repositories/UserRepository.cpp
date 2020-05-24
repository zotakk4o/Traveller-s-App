#include "UserRepository.h"
#include "../config/AppConfig.h"

User getUser(const String& username) {
	Vector<String> row = AppConfig::mainDB.selectFromTable({AppConfig::usersTable, "username", username});

	if (!row.getSize()) {
		return User{};
	}
	Vector<String> data = row[0].split(AppConfig::fileDelimiter);
	return User{ data[0], data[1], data[2]};
}

Vector<User> getAllUsers() {
	Vector<String> rows = AppConfig::mainDB.selectFromTable({ AppConfig::usersTable, "username", username });
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

Vector<Excursion> getUserExcursions(const User&, const String & = "") {

}

Vector<User> selectUsers(const Vector<String>&) {

}

void insertUser(const User&) {

}

void updateUser(const User&) {

}

void deleteUser(const User&) {

}