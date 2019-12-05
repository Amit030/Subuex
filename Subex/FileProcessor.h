#pragma once
#include"FileParser.h"
class FileProcessor
{
private:

	ifstream  *m_pFile;
	std::string path;
	FileParser fileParser;
	


public:
	FileProcessor(std::string path);
	void readFile();
	~FileProcessor();
};

