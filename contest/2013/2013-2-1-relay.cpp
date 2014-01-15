#include <iostream>
#include <fstream>
 
#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i, x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)
 
using namespace std;

typedef unsigned short int ushort;

ushort findcows(ushort *cows, ushort N, ushort target){
	ushort counter = 0;
	loopi(N)
		if(cows[i] == target){
			counter += 1 + findcows(cows, N, i + 1);
		}
	return counter;
}

int main() {
	ofstream fout ("relay.out");
	ifstream fin ("relay.in");
	// get input
	ushort N;
	fin >> N;
	ushort *cows = new ushort[N];
	loopi(N)
		fin >> cows[i];
	// process
	// every cow that forwards to 0, cows that forward to those, cows to those, etc...
	ushort result = findcows(cows, N, 0);
	// output
	fout << result << endl;
	// cleanup
	fin.close();
	fout.close();
	delete[] cows;
	return 0;
}