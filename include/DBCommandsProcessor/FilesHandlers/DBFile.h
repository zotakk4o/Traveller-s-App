#ifndef DBFILE_H
#define DBFILE_H

#include "include/File.h"
#include "TableFile.h"
#include "include/String.h"
#include "include/Vector.cpp"

class DBFile : public File {
	private:
		Vector<TableFile> tableFiles;

		virtual bool saveData(const String&);
		bool doesTableExist(const String& tableName) const;
	public:
		DBFile(ILogger* = nullptr, const String& = "", bool = false);

		virtual bool open(const String&);
		virtual bool close();

		void addTableToData(const TableFile&);

		void addColumnToTable(const Vector<String>&);
		Vector<String> selectFromTable(const Vector<String>&, const String& = "AND", bool = true);
		void countRowsFromTable(const Vector<String>&);
		void insertRow(const Vector<String>&);
		void deleteFromTable(const Vector<String>&, const String& = "AND");
		void updateTableEntry(const Vector<String>&);
		void showTables();
		String innerJoinTables(const Vector<String>&);
		void importTable(const String&);
		void exportTable(const String&, const String&);
		void describeTable(const String&);
		void printTable(const String&);
		void renameTable(const String&, const String&);
		double aggregate(const Vector<String>&);

		TableFile& getTableWithName(const String&);
		Vector<String> generateInCriteria(const String&, const Vector<String>&) const;
};

#endif
