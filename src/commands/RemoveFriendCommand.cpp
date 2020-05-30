#include "RemoveFriendCommand.h"
#include "../config/AppErrors.h"
#include "../config/AppConfig.h"
#include "../config/AppMessages.h"
#include "../models/User.h"
#include "../repositories/FriendshipRepository.h"
#include "../repositories/UserRepository.h"

RemoveFriendCommand::~RemoveFriendCommand() {}

const unsigned short RemoveFriendCommand::getParametersCount() const {
	return 3;
}

String RemoveFriendCommand::toString() const {
	return "remove friend";
}

void RemoveFriendCommand::execute(User& loggedIn, Vector<String>& parameters) const {
	User other = UserRepository::getUser(parameters[0]);

	if (!other.getUsername().getLength()) {
		throw AppErrors::noUserFoundError;
	}

	if (!FriendshipRepository::areFriends(loggedIn, other)) {
		AppConfig::consoleLogger.log(AppMessages::friendshipDoesNotExistMessage + other.getUsername());
		return;
	}

	FriendshipRepository::deleteFriendship(loggedIn, other);

	AppConfig::consoleLogger.log(AppMessages::successfulRemoveFriendMessage + other.getUsername());
}