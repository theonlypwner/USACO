#include <iostream>
#include <fstream>

#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i, x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

int N;

// based on http://math.stackexchange.com/questions/494971/how-to-determine-the-number-of-degrees-overlap-between-two-circular-slices
int abswrap(int diff){
	// diff = wrap(diff)
	// diff if -N/2 <= diff <= N/2
	// diff + N if diff < -N/2
	if(diff < -N/2)
		diff += N;
	// diff - N if diff > N/2
	else if(diff > N/2)
		diff -= N;
	// return abs(wrap(diff))
	return abs(diff);
}
int overlap(int a, int b){
	// 2.5 + 2.5 - abswrap(a - b)
	// but 0 if negative
	return max(0, 5 - abswrap(a - b));
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