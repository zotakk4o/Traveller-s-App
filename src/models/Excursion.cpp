#include "Excursion.h"
#include "../config/AppConfig.h"
#include "../config/AppErrors.h"

Excursion::Excursion() : grade(-1) {}

Excursion::Excursion(const String& destination, const Date& firstDate, const Date& secondDate, const unsigned short& grade, const String& comment, const Vector<String>& photos) {
	if (!AppConfig::isTextValid(destination, { ' ', ',' })) {
		throw AppErrors::invalidDestinationError;
	}

	if (firstDate.toString() > secondDate.toString()) {
		throw AppErrors::invalidDatePeriod;
	}

	if (grade > AppConfig::gradeBoundaries[1] || grade < AppConfig::gradeBoundaries[0]) {
		throw AppErrors::invalidGradeError;
	}

	if (!AppConfig::areBannedFound(comment)) {
		throw AppErrors::invalidCommentError;
	}

	unsigned int photosSize = photos.getSize();
	for (unsigned int i = 0; i < photosSize; i++)
	{
		this->addPhoto(photos[i]);
	}

	this->destination = destination;
	this->firstDate = firstDate;
	this->secondDate = secondDate;
	this->grade = grade;
	this->comment = comment;
}

Excursion& Excursion::operator=(const Excursion& other) {
	if (this != &other && other.firstDate.isDateValid()) {
		this->destination = other.destination;
		this->firstDate = other.firstDate;
		this->secondDate = other.secondDate;
		this->grade = other.grade;
		this->comment = other.comment;
		this->photos = other.photos;
	}

	return *this;
}

const String& Excursion::getDestination() const {
	return this->destination;
}

const Date& Excursion::getFirstDate() const {
	return this->firstDate;
}

const Date& Excursion::getSecondDate() const {
	return this->secondDate;
}

const unsigned short& Excursion::getGrade() const {
	return this->grade;
}

const String& Excursion::getComment() const {
	return this->comment;
}

const Vector<String>& Excursion::getPhotos() const {
	return this->photos;
}

void Excursion::addPhoto(const String& filename) {
	bool wasExtensionMatched = false;
	int index;
	unsigned int extensionsSize = AppConfig::allowedImageExtensions.getSize();
	for (unsigned int i = 0; i < extensionsSize; i++)
	{
		index = filename.indexOf(AppConfig::allowedImageExtensions[i]);

		if (index != -1 && AppConfig::allowedImageExtensions[i].getLength() + index == filename.getLength()) {
			wasExtensionMatched = true;
			break;
		}
	}

	if (!wasExtensionMatched) {
		throw AppErrors::invalidImageExtensionError;
	}

	if (!AppConfig::isTextValid(filename, { '_' })) {
		throw AppErrors::invalidImageNameError;
	}

	this->photos.pushBack(filename);
}