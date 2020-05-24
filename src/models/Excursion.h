#ifndef EXCURSION_H
#define EXCURSION_H

#include "include/String.h"
#include "include/Date.h"

class Excursion {
	private:
		String destination;
		Date firstDate;
		Date secondDate;
		unsigned short grade;
		String comment;
		Vector<String> photos;

	public:
		Excursion();
		Excursion(const String&, const Date&, const Date&, const unsigned short&, const String&, const Vector<String>&);
		Excursion& operator=(const Excursion&);

		void addPhoto(const String&);
		const String& getDestination() const;
		const Date& getFirstDate() const;
		const Date& getSecondDate() const;
		const unsigned short& getGrade() const;
		const String& getComment() const;
		const Vector<String>& getPhotos() const;
};

#endif