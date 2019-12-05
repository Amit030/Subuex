#include "pch.h"
#include "FileProcessor.h"




FileProcessor::FileProcessor(std ::string path)
{

	this->path = path;
}

void 
FileProcessor  :: readFile() {

	std::string line;
	std::ifstream infile;
	infile.open(path,ios::in);
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		std::string tempstr;
		if (!(iss >> tempstr)) { break; } // error
		fileParser.processInput(line);
	
	}
	fileParser.printOutput();
}

FileProcessor::~FileProcessor()
{
	if (nullptr != m_pFile) {
		delete m_pFile;
		m_pFile = nullptr;
	}
}
