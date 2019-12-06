#pragma once
#include"CommanHeaders.h"
#include<vector>
#include<map>
#include<algorithm>

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
		


			string status;
			getCallstatus(&status);
			temp += "|" + status;
			temp += "|" + uniqueID;
			return temp;
		
		}
		void getCallstatus(string *status) {

			//s1.compare(s1)) == 0)
			string first= callStatuslist.at(0);
			string last = callStatuslist.at(callStatuslist.size() - 1);
			if (first.compare("INVITE")== 0 &&
				(
				   last.compare("BYE") == 0
				|| last.compare("CANCEL") == 0
				|| last.compare("ERROR") == 0
				)
				) {
				*status = "Complete";
			}
			else if(first == "INVITE") {
				*status=  "InProgress";
			}
		}
	};
	map<string, stCallDeatil>m_callRegister;
public:
	FileParser();
	void processInput( std::string input);
	void printOutput();
	~FileParser();
};

