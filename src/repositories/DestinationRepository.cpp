#include "DestinationRepository.h"
#include "../config/AppConfig.h"
#include "include/DBCommandsProcessor/config/DCPConfig.h"
#include "UserRepository.h"


Destination DestinationRepository::getDestination(const String& destination) {
	Vector<Destination> res = DestinationRepository::mapToDestinations(
		AppConfig::mainDB.selectFromTable({
			"destination", destination, 
			AppConfig::destinationsTable 
		})
	);

	return res.getSize() > 0 ? res[0] : Destination{};
}

Vector<Destination> DestinationRepository::getAllDestinations() {
	return DestinationRepository::mapToDestinations(AppConfig::mainDB.getTableWithName(AppConfig::destinationsTable).getTableData());
}

Vector<Destination> DestinationRepository::selectDestinations(const Vector<String>& criteria) {
	Vector<String> select = AppConfig::mainDB.generateInCriteria("destination", criteria);
	select.pushBack(AppConfig::destinationsTable);

	return DestinationRepository::mapToDestinations(AppConfig::mainDB.selectFromTable(criteria));
}

void DestinationRepository::insertDestination(const Destination& destination) {
	Vector<String> usernames = UserRepository::extractUsernames(destination.getUsers());
	String usernamesString = !usernames.getSize() ? DCPConfig::nullValue : String::join(usernames, AppConfig::vectorValuesDelimiter);

	AppConfig::mainDB.insertRow({
		AppConfig::destinationsTable, 
		destination.getDestination(),
		usernamesString
	});

	AppConfig::mainDB.save();
}

void DestinationRepository::updateDestination(const Destination& destination) {
	Vector<String> usernames = UserRepository::extractUsernames(destination.getUsers());

	AppConfig::mainDB.updateTableEntry({
		AppConfig::destinationsTable,
		"destination", destination.getDestination(),
		"users", String::join(usernames, AppConfig::vectorValuesDelimiter)
	});

	AppConfig::mainDB.save();
}

void DestinationRepository::deleteDestination(const Destination& destination) {
	AppConfig::mainDB.deleteFromTable({
		AppConfig::destinationsTable, 
		"destination", destination.getDestination()
	});

	AppConfig::mainDB.save();
}

Vector<Destination> DestinationRepository::mapToDestinations(const Vector<String>& rows) {
	if (!rows.getSize()) {
		return Vector<Destination>{};
	}

	Vector<Destination> res;

	unsigned int rowsSize = rows.getSize();
	for (unsigned int i = 0; i < rowsSize; i++)
	{
		Vector<String> data = rows[i].split(AppConfig::fileDelimiter);
		Vector<String> usernames = data[1].split(AppConfig::vectorValuesDelimiter);
		Vector<User> users;
		if (usernames.getSize() == 1 && usernames[0] == DCPConfig::nullValue) {
			usernames = {};
		}
		else {
			users = UserRepository::selectUsers(
				AppConfig::mainDB.generateInCriteria("username", usernames)
			);
		}

		res.pushBack({data[0], users});
	}

	return res;
}