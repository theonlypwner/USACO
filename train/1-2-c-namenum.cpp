/*
ID: victor4
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string serializeName(const string &in){
	string ret = "";
	for(int i = 0; i < in.length(); ++i){
		if(in[i] == 'Q' || in[i] == 'Z')
			return "1";
		if(in[i] < 'Q')
			ret += ((in[i] - 'A') / 3) + '2';
		else
			ret += ((in[i] - 'Q') / 3) + '7';
	}
	return ret;
}

int main() {
	ofstream fout ("namenum.out");
	ifstream fin ("namenum.in"), fdict ("dict.txt");
	
	string serial;
	fin >> serial;
	
	bool found = false;
	string entry;
	while(fdict >> entry)
		if(entry.length() == serial.length() && serializeName(entry) == serial){
			found = true;
			fout << entry << endl;
		}
	
	if(!found)
		fout << "NONE" << endl;
	
	// fout
	return 0;
}