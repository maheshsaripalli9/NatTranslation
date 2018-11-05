#include<iostream>
#include<iomanip>
#include<vector>
#include <fstream>

using namespace std;

int main(){
	string NATString;
	string ip,port,pair1,pair2;
	vector<string> FirstIp,FirstPort,SecondPair;
	bool flag;

	ifstream nat("NAT.txt");
	// Looping through input file and storing in vector
	while(nat >> NATString){
		// Pushing pair2 into SecondPair vector
		int delimeter = NATString.find(',');
		pair2 = NATString.substr(delimeter+1);
		SecondPair.push_back(pair2);
		pair1 = NATString.substr(0,delimeter);

		// Pushing pair into IP,Port vector
		int delimeter2 = pair1.find(':');
		ip = pair1.substr(0,delimeter2);
		port = pair1.substr(delimeter2+1,4);
		FirstIp.push_back(ip);
		FirstPort.push_back(port);
	}

	// Looping through flow file and updating output file accordingly
	ifstream flow("FLOW.txt");
	ofstream output ("OUTPUT.txt");
	string str;

	while(flow >> NATString){
		int temp = NATString.find(':');
		ip = NATString.substr(0,temp);
		port = NATString.substr(temp+1);

		flag = false;
		for(int i=0;i<FirstIp.size();i++){
			str = SecondPair[i] ;
			if(ip == FirstIp[i] || FirstIp[i] == "*"){
				if(port == FirstPort[i] || FirstPort[i] == "*" ){
					output << NATString + " -> " + SecondPair[i] + "\n";

					break;
				}
			}
		}
		 output << "No nat match for " + NATString + "\n";

	}

}
