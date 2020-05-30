#ifndef EXCURSIONREPOSITORY_H
#define EXCURSIONREPOSITORY_H

#include "include/String.h"
#include "../models/Excursion.h"
#include "../models/User.h"

class ExcursionRepository {
	private:
		User tableOwner;

		Vector<Excursion> mapToExcursions(const Vector<String>&);
	public:
		ExcursionRepository(const User&);
		Excursion getExcursion(const String&);
		Vector<Excursion> getAllExcursions();

		Vector<Excursion> selectExcursions(const Vector<String>&);
		void insertExcursion(const Excursion&, bool = true);
		void deleteExcursion(const Excursion&, bool = true);
};

#endif
