#include "ExcursionRepository.h"
#include "../config/AppConfig.h"
#include "include/DBCommandsProcessor/config/DCPConfig.h"
#include "include/Date.h"

ExcursionRepository::ExcursionRepository(const User& user) : tableOwner(user) {}

Excursion ExcursionRepository::getExcursion(const String& destination) {
	Vector<Excursion> res = this->mapToExcursions(AppConfig::mainDB.selectFromTable({ "destination", destination, this->tableOwner.getUsername() }));

	return res.getSize() > 0 ? res[0] : Excursion{};
}

Vector<Excursion> ExcursionRepository::getAllExcursions() {
	return this->mapToExcursions(AppConfig::mainDB.getTableWithName(this->tableOwner.getUsername()).getTableData());
}

Vector<Excursion> ExcursionRepository::selectExcursions(const Vector<String>& criteria) {
	return this->mapToExcursions(AppConfig::mainDB.selectFromTable({ criteria[0], criteria[1], this->tableOwner.getUsername() }));
}

void ExcursionRepository::insertExcursion(const Excursion& excursion) {
	String photos = String::join(excursion.getPhotos(), AppConfig::vectorValuesDelimiter);
	if (!photos.getLength()) {
		photos = DCPConfig::nullValue;
	}
	AppConfig::mainDB.insertRow({ 
		this->tableOwner.getUsername(), 
		excursion.getDestination(),
		excursion.getFirstDate().toString(),
		excursion.getSecondDate().toString(),
		String::toString(excursion.getGrade()),
		excursion.getComment(),
		photos
	});
	AppConfig::mainDB.save();
}

void ExcursionRepository::deleteExcursion(const Excursion& excursion) {
	AppConfig::mainDB.deleteFromTable({
		this->tableOwner.getUsername(),
		"destination", excursion.getDestination()
	});
	AppConfig::mainDB.save();
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
		Vector<String> photos = data[5].split(AppConfig::vectorValuesDelimiter);
		if (photos.getSize() == 1 && photos[0] == DCPConfig::nullValue) {
			photos = {};
		}
		res.pushBack(Excursion{ data[0], Date{data[1]}, Date{data[2]}, (unsigned short)String::toInt(data[3]), data[4], photos });
	}

	return res;
}