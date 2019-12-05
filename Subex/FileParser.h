#pragma once
#include"CommanHeaders.h"
#include<vector>
#include<map>

class FileParser
{
private :
	struct stCallDeatil {
		std::string startTime;
		std::string endTime;
		std::string srcIP;
		std::string destIP;
		std::string callingParty;
		std::string calledPart;
		vector< std::string>callStatuslist;
		std::string uniqueID;


		stCallDeatil() {
			startTime = "NULL";
			endTime = "NULL";
			srcIP = "NULL";
			destIP = "NULL";
			callingParty = "NULL";
			calledPart = "NULL";
			uniqueID = "NULL";
		}

		string print() {
			string temp = startTime + "|" + endTime + "|" + srcIP + "|" + destIP + "|" + callingParty + "|" + calledPart + "|";
			bool flag = true;
			for (auto x : callStatuslist) {
				if (!flag) {
					temp += ",";			
				}
				flag = false;
				temp += x;				
				
			}
			temp += "|" + uniqueID;
			return temp;
		
		}
	};
	map<string, stCallDeatil>m_callRegister;
public:
	FileParser();
	void processInput( std::string input);
	void printOutput();
	~FileParser();
};

