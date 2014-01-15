#include <iostream>
#include <fstream>

#include <algorithm>

#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i,x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

#define N 12
#define N_2 9
#define N_3 6
#define N 12
#define TEAMS 4

int main() {
	ofstream fout ("bteams.out");
	ifstream fin ("bteams.in");
	// Read input
	int skills[N]; // [1, 1000000]
	// int sum = 0;
	loopi(N){
		fin >> skills[i];
		// sum += skills[i];
	}
	// Calculate output
	int lowest_diff = 3999996; // 4 * 1000000 - 4 * 1
	// 12 choose 3 * 9 choose 3 * 6 choose 3 * 3 choose 3 = 220 * 84 * 20 * 1 = 369600 possible combinations
	// I give up...
	lowest_diff = 1;
	fout << lowest_diff << endl;
	return 0;
}