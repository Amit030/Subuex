#include "pch.h"
#include "FileParser.h"


FileParser::FileParser()
{
}

void FileParser::processInput( std::string input)
{
	// Vector of string to save tokens 
	vector <string> tokens;

	// stringstream class check1 
	stringstream check1(input);

	string intermediate;

	// Tokenizing w.r.t. space ',' 
	while (getline(check1, intermediate, ','))
	{
		tokens.push_back(intermediate);
	}
	string key = tokens[tokens.size() - 1];
	auto it = m_callRegister.find(key);
	if (m_callRegister.end() != it ) {
		string str = tokens[tokens.size() - 2];
		str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
		m_callRegister.at(key).callStatuslist.push_back(str);
		m_callRegister.at(key).endTime= tokens[0];
	}
	else {
		stCallDeatil callDetail;
		callDetail.startTime = tokens[0];
		callDetail.srcIP = tokens[1];
		callDetail.destIP = tokens[2];
		callDetail.callingParty = tokens[3];
		callDetail.calledPart = tokens[4];
		string str = tokens[5];
		str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
		 callDetail.callStatuslist.push_back(str);
		callDetail.uniqueID = key;
		m_callRegister.insert({ key, callDetail });
	}

	

}

void FileParser::printOutput()
{
	for (auto i : m_callRegister) {
		cout << i.second.print() << endl;
	}
}


FileParser::~FileParser()
{
}
