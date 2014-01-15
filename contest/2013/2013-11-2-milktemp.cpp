#include <iostream>
#include <fstream>

#include <set>

#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i, x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

int N, X, Y, Z;

int main() {
	ofstream fout ("milktemp.out");
	ifstream fin ("milktemp.in");
	// get input
	fin >> N >> X >> Y >> Z;
	// calculate
	int *a = new int[N], *b = new int[N];
	set<int> boundaries;
	loopi(N) {
		fin >> a[i] >> b[i];
		boundaries.insert(a[i]);
		boundaries.insert(b[i]);
	}
	int best_score = 0, best_suitable = 0;
	for (set<int>::iterator it = boundaries.begin(); it != boundaries.end(); ++it) {
		int too_low = 0, too_high = 0, suitable = 0;
		loopi(N) {
			if(a[i] > *it)
				++too_low;
			else if(b[i] < *it)
				++too_high;
			else
				++suitable;
		}
		// The best solution has as many as possible in the suitable range
		if(suitable < best_suitable)
			continue;
		best_suitable = suitable;
		// Update best score
		const int new_score = X * too_low + Y * suitable + Z * too_high;
		if(new_score > best_score)
			best_score = new_score;
	}
	// Write output
	fout << best_score;
	// Clean up
	delete[] a;
	delete[] b;
	return 0;
}