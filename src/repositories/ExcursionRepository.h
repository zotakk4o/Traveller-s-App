#ifndef EXCURSIONREPOSITORY_H
#define EXCURSIONREPOSITORY_H

#include "include/String.h"
#include "../models/Excursion.h"
#include "../models/User.h"

class ExcursionRepository {
	private:
		User tableOwner;
	public:
		Excursion getExcursion(const String&);
		Vector<Excursion> getAllExcursions();

		Vector<Excursion> selectExcursions(const Vector<String>&);
		void insertExcursion(const Excursion&);
		void updateExcursion(const Excursion&);
		void deleteExcursion(const Excursion&);
};

#endif
