#include "UserRepository.h"
#include "../config/AppConfig.h"

User getUser(const String& username) {
	Vector<String> row = AppConfig::mainDB.selectFromTable({AppConfig::usersTable, "username", username});
	if (!row.getSize()) {
		return User{};
	}

	return User{row[0], row[1], row[2]};
}

Vector<User> getAllUsers() {
	Vector<String> rows = AppConfig::mainDB.selectFromTable({ AppConfig::usersTable, "username", username });
	if (!row.getSize()) {
		return Vector<User>{};
	}

	return User{ row[0], row[1], row[2] };
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