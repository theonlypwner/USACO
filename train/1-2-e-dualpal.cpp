/*
ID: victor4
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

#include <algorithm>

using namespace std;

inline char to_char(int c){
	if(c >= 10)
		return c - 10 + 'A';
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
	ofstream fout ("dualpal.out");
	ifstream fin ("dualpal.in");
	int N, S;
	fin >> N >> S;
	
	while(N){
		if(++S > 100000)
			break;
		int num = 0;
		for(int j = 2; j <= 10; ++j){
			// fail: I put S * S instead of S
			string check = tobase(S, j);
			if(check == reverse_str(check) && ++num >= 2){
				--N;
				fout << S << endl;
				break;
			}
		}
	}
	
	return 0;
}