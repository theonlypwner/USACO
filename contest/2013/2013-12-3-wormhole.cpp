#include <iostream>
#include <fstream>

#include <map>

#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i, x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

// table for n! from 0! to 12!
const unsigned int factorial[] = {
	1,
	1,
	2,
	6,
	24,
	120,
	720,
	5040,
	40320,
	362880,
	3628800,
	39916800,
	479001600,
};

// table for 2^n from 2^0 to 2^6
const unsigned int pow2N[] = {
	1,
	2,
	4,
	8,
	16,
	32,
	64,
};

int pairings(int N){
	return factorial[N]/pow2N[N/2+1];
}

int main() {
	ofstream fout ("wormhole.out");
	ifstream fin ("wormhole.in");
	// Count number of wormholes per row
	int N;
	fin >> N;
	map<int, int> counts;
	loopi(N){
		int x, y;
		fin >> x >> y;
		++counts[y];
	}
	int total = pairings(N);
	// Count the rows with one item
	int rows_with_one = 0;
	// Calculate the working combinations of the remaining...
	int remaining_combinations = 0;
	int working = remaining_combinations * pairings(rows_with_one);
	fout << (total - working) << endl;
	return 0;
}
