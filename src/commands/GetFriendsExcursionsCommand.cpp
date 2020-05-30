#include "GetFriendsExcursionsCommand.h"
#include "../repositories/DestinationRepository.h"
#include "../repositories/ExcursionRepository.h"
#include "../repositories/UserRepository.h"
#include "../repositories/FriendshipRepository.h"
#include "../config/AppConfig.h"
#include "../config/AppErrors.h"
#include "../config/AppMessages.h"

GetFriendsExcursionsCommand::~GetFriendsExcursionsCommand() {}

const unsigned short GetFriendsExcursionsCommand::getParametersCount() const {
	return 4;
}

String GetFriendsExcursionsCommand::toString() const {
	return "get friend grade";
}

void GetFriendsExcursionsCommand::execute(User& loggedIn, Vector<String>& parameters) const {
	User friendo = UserRepository::getUser(parameters[0]);

	if (!friendo.getUsername().getLength()) {
		throw AppErrors::noUserFoundError;
	}

	if (!FriendshipRepository::areFriends(loggedIn, friendo)) {
		AppConfig::consoleLogger.log(AppMessages::friendshipDoesNotExistMessage + friendo.getUsername());
		return;
	}

	Vector<Excursion> excursions = friendo.getAllExcursions();
	unsigned int excursionsSize = excursions.getSize();
	for (unsigned int i = 0; i < excursionsSize; i++)
	{
		AppConfig::consoleLogger.log(String{ "Destination: " } + excursions[i].getDestination() + ':');
		AppConfig::consoleLogger.log(String{ "Comment: " } +excursions[i].getComment());
		AppConfig::consoleLogger.log(String{ "Grade: " } +String::toString(excursions[i].getGrade()));
	}
}