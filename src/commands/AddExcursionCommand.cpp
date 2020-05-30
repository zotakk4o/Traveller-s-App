#include "AddExcursionCommand.h"
#include "../repositories/DestinationRepository.h"
#include "../repositories/ExcursionRepository.h"
#include "../models/Excursion.h"
#include "../config/AppConfig.h"
#include "../config/AppErrors.h"
#include "../config/AppMessages.h"

AddExcursionCommand::~AddExcursionCommand() {}

const unsigned short AddExcursionCommand::getParametersCount() const {
	return 2;
}

String AddExcursionCommand::toString() const {
	return "add excursion";
}

void AddExcursionCommand::execute(User& loggedIn, Vector<String>& keywords) const {
	Vector<String> data;
	Vector<String> sampleData = {
		"Sample destination",
		"15.05.2020",
		"16.05.2020",
		"3",
		"wth bro",
		"pesho.png"
	};

	Vector<String> messages{
		AppMessages::enterDestinationMessage,
		AppMessages::enterDatePeriodMessage,
		AppMessages::enterDatePeriodMessage,
		AppMessages::enterGradeMessage,
		AppMessages::enterCommentMessage,
		AppMessages::enterPhotosMessage
	};

	String currCommand;
	int currCommandIndex = 0;

	while (true) {
		AppConfig::consoleLogger.log(messages[currCommandIndex]);
		String::getLine(AppConfig::inputStream, currCommand);

		if (currCommand == AppConfig::cancelCommand) {
			AppConfig::consoleLogger.log(AppMessages::loginCancelledMessage);
			return;
		}

		try
		{
			data = sampleData;

			if (currCommandIndex == 1) {
				Vector<String> dates = currCommand.split('-');
				if (dates.getSize() != 2) {
					throw AppErrors::invalidDatePeriod;
				}

				data[1] = dates[0];
				data[2] = dates[1];
			}
			else {
				data[currCommandIndex] = currCommand;
			}
			
			if (currCommandIndex == 3 && String::isNumeric(currCommand) != 0) {
				throw AppErrors::invalidGradeError;
			}

			Excursion(data[0], Date{ data[1] }, Date{ data[2] }, String::toInt(data[3]), data[4], data[5].split(' '));
			
			if (currCommandIndex == 1) {
				sampleData[1] = data[1];
				sampleData[2] = data[2];
			} 
			else {
				sampleData[currCommandIndex] = currCommand;
			}
		}
		catch (const String& err)
		{
			AppConfig::consoleLogger.log(err);
			continue;
		}

		if (currCommandIndex == 1) {
			currCommandIndex++;
		}
		currCommandIndex++;

		if (currCommandIndex == sampleData.getSize()) {
			break;
		}
	}

	Excursion newExcursion = Excursion(data[0], Date{ data[1] }, Date{ data[2] }, String::toInt(data[3]), data[4], data[5].split(' '));
	ExcursionRepository repo{ loggedIn };

	if (repo.getExcursion(newExcursion.getDestination()).getDestination().getLength()) {
		AppConfig::consoleLogger.log(AppMessages::alreadyRatedMessage);
		return;
	}

	Destination dest = DestinationRepository::getDestination(newExcursion.getDestination());

	if (!dest.getDestination().getLength()) {
		DestinationRepository::insertDestination(Destination{ newExcursion.getDestination(), {loggedIn} });
	}
	else {
		dest.addUser(loggedIn);
		DestinationRepository::updateDestination(dest);
	}

	repo.insertExcursion(newExcursion);
	loggedIn.addExcursion(newExcursion);

	AppConfig::consoleLogger.log(AppMessages::successfulAddExcursionMessage + data[0]);
}