// Subex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include"FileProcessor.h"
#include <sstream>
#include <string>
int main()
{
	std::string filePath;
	getline(cin, filePath);

	FileProcessor *fileProcessor = new FileProcessor(filePath);
	fileProcessor->readFile();


	return 0;
}


