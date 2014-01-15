#include <iostream>
#include <fstream>
#include <string>

#define loopi(x) loopi_start(x,0)
#define loopi_start(x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

bool isBalanced(string str){
	int opening_count = 0; // (
	int closing_count = 0; // )
	loopi(str.length()){
		if(str[i] == '(') ++opening_count;
		else if(++closing_count > opening_count) return false;
	}
	return opening_count == closing_count; // is it balanced?
}

int main() {
	ofstream fout ("typo.out");
	ifstream fin("typo.in");
	// get input
	string str;
	fin >> str;
	// process
	int typos = 0;
	loopi(str.length()){
		// reverse
		if(str[i] == '(') str[i] = ')';
		else str[i] = '(';
		// check
		if(isBalanced(str)) ++typos;
		// undo
		if(str[i] == '(') str[i] = ')';
		else str[i] = '(';
	}
	// output
	fout << typos << '\n';
	// cleanup
	fin.close();
	fout.close();
	return 0;
}