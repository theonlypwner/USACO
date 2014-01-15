#include <iostream>
#include <fstream>
 
#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i, x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)
 
using namespace std;

bool intersects(int from1, int to1, int from2, int to2){
	return (to2 > to1) != (from2 > from1);
}

int main() {
	ofstream fout ("crossings.out");
	ifstream fin ("crossings.in");
	// get input
	int N;
	fin >> N;
	int *cows_from = new int[N];
	int *cows_to = new int[N];
	bool *cows_safe = new bool[N];
	loopi(N){
		fin >> cows_from[i] >> cows_to[i];
		cows_safe[i] = true;
	}
	// process
	int safe = 0;
	loopi(N){
		if(!cows_safe[i]) continue;
		loop_start(j, N, i + 1)
			if(intersects(cows_from[i], cows_to[i], cows_from[j], cows_to[j])){
				cows_safe[i] = cows_safe[j] = false;
				break;
			}
		if(cows_safe[i]) ++safe;
	}
	// output
	fout << safe << endl;
	// cleanup
	fin.close();
	fout.close();
	delete[] cows_from;
	delete[] cows_to;
	delete[] cows_safe;
	return 0;
}