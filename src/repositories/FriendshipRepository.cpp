#include "FriendshipRepository.h"
#include "UserRepository.h"
#include "../config/AppConfig.h"

Vector<User> FriendshipRepository::selectFriendships(const User& user) {
	return FriendshipRepository::mapToFriends(
		user.getUsername(),
		AppConfig::mainDB.selectFromTable({
			"first", user.getUsername(),
			"second", user.getUsername(),
			AppConfig::friendshipsTable	
		}, "OR")
	);
}

bool FriendshipRepository::areFriends(const User& first, const User& second) {
	return FriendshipRepository::selectFriendships(first).indexOf(second) != -1;
}

void FriendshipRepository::insertFriendship(const User& first, const User& second) {
	AppConfig::mainDB.insertRow({
		AppConfig::friendshipsTable, 
		first.getUsername(), second.getUsername()
	});
	AppConfig::mainDB.save();
}

void FriendshipRepository::deleteFriendship(const User& first, const User& second) {
	AppConfig::mainDB.deleteFromTable({
		AppConfig::friendshipsTable,
		"first", first.getUsername(),
		"second", second.getUsername()
	});

	AppConfig::mainDB.deleteFromTable({
		AppConfig::friendshipsTable,
		"second", first.getUsername(),
		"first", second.getUsername()
	});

	AppConfig::mainDB.save();
}

Vector<User> FriendshipRepository::mapToFriends(const String& currUsername, const Vector<String>& friendships) {
	Vector<User> res;

	unsigned int friendshipsSize = friendships.getSize();
	for (unsigned int i = 0; i < friendshipsSize; i++)
	{
		Vector<String> usernames = friendships[i].split(AppConfig::fileDelimiter);
		if (usernames[0] == currUsername) {
			res.pushBack(UserRepository::getUser(usernames[1]));
		}
		else {
			res.pushBack(UserRepository::getUser(usernames[0]));
		}
	}

	return res;
}