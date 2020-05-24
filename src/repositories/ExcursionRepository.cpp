#include "ExcursionRepository.h"
#include "../config/AppConfig.h"
#include "include/Date.h"

ExcursionRepository::ExcursionRepository(const User& user) : tableOwner(user) {}

Excursion ExcursionRepository::getExcursion(const String& destination) {
	return this->mapToExcursions(AppConfig::mainDB.selectFromTable({ "destination", destination, this->tableOwner.getUsername() }))[0];
}

Vector<Excursion> ExcursionRepository::getAllExcursions() {
	return this->mapToExcursions(AppConfig::mainDB.getTableWithName(this->tableOwner.getUsername()).getTableData());
}

Vector<Excursion> ExcursionRepository::selectExcursions(const Vector<String>& criteria) {
	return this->mapToExcursions(AppConfig::mainDB.selectFromTable({ criteria[0], criteria[1], this->tableOwner.getUsername() }));
}

void ExcursionRepository::insertExcursion(const Excursion& excursion) {
	AppConfig::mainDB.insertRow({ this->tableOwner.getUsername(), 
		excursion.getDestination(),
		excursion.getFirstDate().toString(),
		excursion.getSecondDate().toString(),
		String::toString(excursion.getGrade()),
		excursion.getComment(),
		String::join(excursion.getPhotos(), AppConfig::vectorValuesDelimiter)
	});
}

void ExcursionRepository::deleteExcursion(const Excursion& excursion) {
	AppConfig::mainDB.deleteFromTable({this->tableOwner.getUsername(), "destination", excursion.getDestination()});
}

Vector<Excursion> ExcursionRepository::mapToExcursions(const Vector<String>& rows) {
	if (!rows.getSize()) {
		return Vector<Excursion>{};
	}

	Vector<Excursion> res;

	unsigned int rowsSize = rows.getSize();
	for (unsigned int i = 0; i < rowsSize; i++)
	{
		Vector<String> data = rows[i].split(AppConfig::fileDelimiter);
		res.pushBack(Excursion{ data[0], Date{data[1]}, Date{data[2]}, String::toInt(data[3]), data[4], data[5].split(AppConfig::vectorValuesDelimiter) });
	}

	return res;
}