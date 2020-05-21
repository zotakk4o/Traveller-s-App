#ifndef FILE_H
#define FILE_H
#include<fstream>
#include "String.h"
#include "Loggers/interfaces/ILogger.h"

class File {
	protected:
		String data;
		String path;
		bool opened;
		const ILogger* logger;

		virtual bool saveData(const String&);
	public:
		File(const ILogger* = nullptr, const String& = "");
		File(const File& other);

		virtual ~File();
		virtual bool open(const String&) = 0;
		virtual bool save();
		virtual bool saveAs(const String&);
		virtual bool close();
		void setData(const String&);

		static String getFileName(const String&, bool = true);
		String getData() const;
		String getPath() const;
		bool isOpened() const;
};
#endif