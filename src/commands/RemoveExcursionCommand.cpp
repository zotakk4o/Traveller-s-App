#include "RemoveExcursionCommand.h"
#include "../config/AppConfig.h"
#include "../config/AppErrors.h"
#include "../config/AppMessages.h"
#include "../repositories/DestinationRepository.h"
#include "../repositories/ExcursionRepository.h"
#include "../repositories/UserRepository.h"
#include "../models/Destination.h"
#include "../models/Excursion.h"

RemoveExcursionCommand::~RemoveExcursionCommand() {}

const unsigned short RemoveExcursionCommand::getParametersCount() const {
	return 3;
}

String RemoveExcursionCommand::toString() const {
	return "remove excursion";
}

void RemoveExcursionCommand::execute(User& loggedIn, Vector<String>& parameters) const {
	int toBeDeletedIndex = loggedIn.getExcursionIndex(parameters[0]);

	if (toBeDeletedIndex == -1) {
		throw AppErrors::destinationNotVisitedError + parameters[0];
	}

	Vector<Excursion> excursions = loggedIn.getAllExcursions();

	ExcursionRepository repo{ loggedIn };
	repo.deleteExcursion(excursions[toBeDeletedIndex], false);

	Destination destination = DestinationRepository::getDestination(parameters[0]);
	destination.removeUser(loggedIn);
	
	DestinationRepository::updateDestination(destination);

	excursions.removeAtIndex(toBeDeletedIndex);
	loggedIn.setExcursions(excursions);

	AppConfig::consoleLogger.log(AppMessages::successfulRemoveExcursionMessage + parameters[0]);
}