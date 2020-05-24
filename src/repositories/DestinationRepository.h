#ifndef DESTINATIONREPOSITORY_H
#define DESTINATIONREPOSITORY_H

#include "include/String.h"
#include "../models/User.h"
#include "../models/Destination.h"
#include "../models/Excursion.h"

class DestinationRepository {
	private:
		Vector<Destination> matpToDestinations(const Vector<String>&);
	public:
		Destination getDestination(const String&);
		Vector<Destination> getAllDestinations();
		Vector<Destination> selectDestinations(const Vector<String>&);
		
		void insertDestination(const Destination&);
		void updateDestination(const Destination&);
		void deleteDestination(const Destination&);
};

#endif
