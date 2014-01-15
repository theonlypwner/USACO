/*
ID: victor4
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// const int daysinmonth[12] = {  };
int daysinmonth(int month, int year){
	// 1 = January
	if(month == 1)
		// year is offset from 1900
		// 1900 % 4 = 0 = 1900 % 100 = 0, 1900 % 400 = 300
		/*
		(leap year) iff (divisible by 4) and (not (divisible by 100) or (divisible by 400))
		not (leap year) iff not( (divisible by 4) and (not (divisible by 100) or (divisible by 400)))
		not (leap year) iff (not (divisible by 4)) or (not (not (divisible by 100) or (divisible by 400)))
		not (leap year) iff (not (divisible by 4)) or ((divisible by 100) and not (divisible by 400))
		*/
		return ((year % 4) || (!(year % 100) && ((year+300) % 400))) ? 28 : 29;
	// September, April, June, and November
	switch(month){
		case 8:
		case 3:
		case 5:
		case 10:
			return 30;
			// break;
		default:
			return 31;
			// break;
	}
}

int main() {
	ofstream fout ("friday.out");
	ifstream fin ("friday.in");
	
	// sanitize input
	int N;
	fin >> N;
	if(N < 0) N = 0;
	if(N > 400) N = 400;
	
	// failed once due to forgetting the = {0}
	int result[7] = {0};
	
	int dow = 0, month = 0;
	for(int i = 0; i < N; ++i)
		for(int m = 0; m < 12; ++m){
			// (a + 13) mod 7 = (a + 6) mod 7
			++result[((dow + 6) % 7)];
			dow = (dow + daysinmonth(m, i)) % 7;
		}
	
	// output!
	for(int i = 0; i < 7; ++i){
		// failreason: Saturday first!
		fout << result[(i + 6) % 7];
		if(i == 6) fout << endl;
		else fout << " ";
	}
	return 0;
}