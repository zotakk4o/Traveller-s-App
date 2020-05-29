#ifndef DESTINATIONREPOSITORY_H
#define DESTINATIONREPOSITORY_H

#include "include/String.h"
#include "../models/Destination.h"

class DestinationRepository {
	private:
		static Vector<Destination> mapToDestinations(const Vector<String>&);
	public:
		static Destination getDestination(const String&);
		static Vector<Destination> getAllDestinations();
		static Vector<Destination> selectDestinations(const Vector<String>&);
		
		static void insertDestination(const Destination&);
		static void updateDestination(const Destination&);
		static void deleteDestination(const Destination&);
};

#endif
