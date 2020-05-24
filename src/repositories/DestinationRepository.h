#ifndef DESTINATIONREPOSITORY_H
#define DESTINATIONREPOSITORY_H

#include "include/String.h"
#include "../models/User.h"
#include "../models/Destination.h"
#include "../models/Excursion.h"

class DestinationRepository {
	private:
		static const String tableName;
	public:
		Destination getDestination(const String&);
		Vector<Destination> getAllDestinations();
	
		Vector<Destination> selectDestinations(const Vector<String>&);
		Vector<Excursion> getDestinationExcursions(const String&);
		void insertDestination(const Destination&);
		void updateDestination(const Destination&);
		void deleteDestination(const Destination&);
};

#endif
