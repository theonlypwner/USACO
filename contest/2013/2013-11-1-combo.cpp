#include <iostream>
#include <fstream>

#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i, x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

int N;

int overlap(int a, int b){
	return 5 - abs(a - b) % N;
}

#define NUMCOMBO 3
int main() {
	ofstream fout ("combo.out");
	ifstream fin ("combo.in");
	// get input
	int combo1[NUMCOMBO];
	int combo2[NUMCOMBO];
	fin >> N;
	loopi(NUMCOMBO)
		fin >> combo1[i];
	loopi(NUMCOMBO)
		fin >> combo2[i];
	// calculate:
	int overlap_a = overlap(combo1[0], combo2[0]);
	int overlap_b = overlap_a ? overlap(combo1[1], combo2[1]) : 0;
	int overlap_c = overlap_b ? overlap(combo1[2], combo2[2]) : 0;
	// 2 * min(5, N) ** 3, but subtract the overlap
	// write output
	int abc = min(5, N);
	fout << (2 * abc * abc * abc - overlap_a * overlap_b * overlap_c);
	return 0;
}