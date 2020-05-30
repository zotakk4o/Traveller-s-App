#include "GetDestinationGradeCommand.h"

#include "../repositories/DestinationRepository.h"
#include "../repositories/ExcursionRepository.h"
#include "../repositories/UserRepository.h"
#include "../config/AppConfig.h"
#include "../config/AppErrors.h"
#include "../config/AppMessages.h"

GetDestinationGradeCommand::~GetDestinationGradeCommand() {}

const unsigned short GetDestinationGradeCommand::getParametersCount() const {
	return 4;
}

String GetDestinationGradeCommand::toString() const {
	return "get destination grade";
}

void GetDestinationGradeCommand::execute(User& loggedIn, Vector<String>& parameters) const {
	Destination desiredDestination = DestinationRepository::getDestination(parameters[0]);

	if (!desiredDestination.getDestination().getLength()) {
		throw AppErrors::noDestinationFoundError;
	}

	Vector<User> visitors = desiredDestination.getUsers();
	double averageGrade = 0;

	unsigned int visitorsSize = visitors.getSize();
	for (unsigned int i = 0; i < visitorsSize; i++)
	{
		Excursion visitorsExcursion = visitors[i].getAllExcursions()[visitors[i].getExcursionIndex(desiredDestination.getDestination())];
		averageGrade += visitorsExcursion.getGrade();

		AppConfig::consoleLogger.log(visitors[i].getUsername() + "->" + visitorsExcursion.getDestination() + ':');
		AppConfig::consoleLogger.log(String{ "Comment: " } + visitorsExcursion.getComment());
		AppConfig::consoleLogger.log(String{ "Grade: " } +visitorsExcursion.getGrade());
	}

	AppConfig::consoleLogger.log(String{ "Average Grade: " } + String::toString(averageGrade / visitorsSize, 2));
}