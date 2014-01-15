/*
ID: victor4
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int s_product(const char *s){
	int product = 1;
	for(const char *p = s; *p; ++p)
		product *= *p - 'A' + 1;
	return product;
}

int main() {
	ofstream fout ("ride.out");
	ifstream fin ("ride.in");
	
	string s_in1, s_in2;
	fin >> s_in1 >> s_in2;
	
	fout << (((s_product(s_in1.c_str()) % 47) == (s_product(s_in2.c_str()) % 47)) ? "GO" : "STAY") << endl;
	
	return 0;
}