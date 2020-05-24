#ifndef EXCURSION_H
#define EXCURSION_H

#include "include/String.h"
#include "include/Date.h"

class Excursion {
	private:
		String tableName;
		String destination;
		Date firstDate;
		Date secondDate;
		unsigned short grade;
		String comment;
		Vector<String> photos;

	public:
		Excursion();
		Excursion(const String&, const String&, const Date&, const Date&, const unsigned short&, const String&, const Vector<String>&);
		Excursion& operator=(const Excursion&);

		String getDestination() const;
		Date getFirstDate() const;
		Date getSecondDate() const;
		unsigned short getGrade() const;
		String getComment() const;
		Vector<String> getPhotos() const;
};

#endif