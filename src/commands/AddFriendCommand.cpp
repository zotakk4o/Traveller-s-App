#include "AddFriendCommand.h"
#include "../repositories/FriendshipRepository.h"
#include "../repositories/UserRepository.h"
#include "../config/AppErrors.h"
#include "../config/AppConfig.h"
#include "../config/AppMessages.h"

AddFriendCommand::~AddFriendCommand() {}

const unsigned short AddFriendCommand::getParametersCount() const {
	return 3;
}

String AddFriendCommand::toString() const {
	return "add friend";
}
void AddFriendCommand::execute(User& loggedIn, Vector<String>& parameters) const {
	parameters = parameters.slice(this->toString().split(' ').getSize(), parameters.getSize() - 1);

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