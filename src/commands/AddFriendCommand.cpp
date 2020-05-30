#include "AddFriendCommand.h"
#include "../repositories/FriendshipRepository.h"
#include "../repositories/UserRepository.h"
#include "../config/AppErrors.h"
#include "../config/AppConfig.h"
#include "../config/AppMessages.h"

AddFriendCommand::~AddFriendCommand() {}

const unsigned short AddFriendCommand::getParametersCount() const {
	return 2;
}

String AddFriendCommand::toString() const {
	return "addfriend";
}
void AddFriendCommand::execute(User& loggedIn, const Vector<String>& parameters) const {
	if (loggedIn.getUsername() == parameters[0]) {
		throw AppErrors::cannotMakeYourselfFriend;
	}

	User other = UserRepository::getUser(parameters[0]);

	if (!other.getUsername().getLength()) {
		throw AppErrors::noUserFoundError;
	}
	
	if (FriendshipRepository::areFriends(loggedIn, other)) {
		AppConfig::consoleLogger.log(AppMessages::friendshipAlreadyExistsMessage);
		return;
	}

	FriendshipRepository::insertFriendship(loggedIn, other);

	AppConfig::consoleLogger.log(AppMessages::successfulAddFriendMessage + other.getUsername());
}