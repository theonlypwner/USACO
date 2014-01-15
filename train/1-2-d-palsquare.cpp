/*
ID: victor4
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

#include <algorithm>

using namespace std;

inline char to_char(int c){
	if(c >= 10) return c - 10 + 'A';
	return c + '0';
}

string tobase(int num, int base){
	string ret;
	int div = base;
	while(div < num)
		div *= base;
	for(div /= base;;){
		ret += to_char(num / div);
		// get remainder
		num = num % div;
		// next
		if(div < 2) break;
		div /= base;
	}
	return ret;
}

string reverse_str(string str){
	reverse(str.begin(), str.end());
	return str;
}

int main() {
	ofstream fout ("palsquare.out");
	ifstream fin ("palsquare.in");
	int base;
	fin >> base;
	
	for(int i = 1; i <= 300; ++i){
		string n = tobase(i, base), n2(tobase(i * i, base));
		if(n2 == reverse_str(n2))
			fout << n << " " << n2 << endl;
	}
	
	return 0;
}