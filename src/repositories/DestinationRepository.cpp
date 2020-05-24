#include "DestinationRepository.h"
#include "../config/AppConfig.h"
#include "UserRepository.h"


Destination DestinationRepository::getDestination(const String& destination) {

}

Vector<Destination> DestinationRepository::getAllDestinations() {

}

Vector<Destination> DestinationRepository::selectDestinations(const Vector<String>& criteria) {

}

void DestinationRepository::insertDestination(const Destination&) {

}

void DestinationRepository::updateDestination(const Destination&) {

}

void DestinationRepository::deleteDestination(const Destination&) {

}

Vector<Destination> DestinationRepository::matpToDestinations(const Vector<String>& rows) {
	if (!rows.getSize()) {
		return Vector<Destination>{};
	}

	Vector<Destination> res;

	unsigned int rowsSize = rows.getSize();
	for (unsigned int i = 0; i < rowsSize; i++)
	{
		Vector<String> data = rows[i].split(AppConfig::fileDelimiter);
		Vector<String> usernames = data[1].split(AppConfig::vectorValuesDelimiter);
		
		//TODO IMPLEMENT IN()
	}

	return res;
}