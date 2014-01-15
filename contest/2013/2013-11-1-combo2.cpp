#include <iostream>
#include <fstream>

#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i, x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

int N;

int fixrange(int n){
	--n;
	while(n < 0) n += N;
	return (n % N) + 1;
}

int overlap(int a, int b){
	// I tried with modular arithmetic but couldn't get it working
	// return 5 - min(abs(a - b) % N, N - (abs(a - b) % N));
	int a1 = fixrange(a - 2),
		a2 = fixrange(a - 1),
		a3 = a,
		a4 = fixrange(a + 1),
		a5 = fixrange(a + 2);
	int b1 = fixrange(b - 2),
		b2 = fixrange(b - 1),
		b3 = b,
		b4 = fixrange(b + 1),
		b5 = fixrange(b + 2);
	int total = 0;
	if(a1 == b1 || a1 == b2 || a1 == b3 || a1 == b4 || a1 == b5)
		++total;
	if(a2 == b1 || a2 == b2 || a2 == b3 || a2 == b4 || a2 == b5)
		++total;
	if(a3 == b1 || a3 == b2 || a3 == b3 || a3 == b4 || a3 == b5)
		++total;
	if(a4 == b1 || a4 == b2 || a4 == b3 || a4 == b4 || a4 == b5)
		++total;
	if(a5 == b1 || a5 == b2 || a5 == b3 || a5 == b4 || a5 == b5)
		++total;
	return total;
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
	// Special case: there is always N overlap if N <= 5
	if(N <= 5) // 2 * N ** 3 - N ** 3 = N ** 3
		// write output
		fout << (N * N * N);
	else{
		int overlap_a = overlap(combo1[0], combo2[0]);
		int overlap_b = overlap_a ? overlap(combo1[1], combo2[1]) : 0;
		int overlap_c = overlap_b ? overlap(combo1[2], combo2[2]) : 0;
		// 2 * 5 ** 3, but subtract the overlap
		// write output
		fout << (250 - overlap_a * overlap_b * overlap_c);
	}
	return 0;
}