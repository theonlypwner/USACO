#include <iostream>
#include <fstream>
 
#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i, x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)
 
using namespace std;

struct fence
{
	int x1, y1, x2, y2;
	// each fence is vertical or horizontal
};
fence *fences;

struct cow
{
	int x, y;
};
cow *cows;

int main() {
	ofstream fout ("crazy.out");
	ifstream fin ("crazy.in");
	// get input
	unsigned int N, C;
	fin >> N >> C;
	fences = new fence[N];
	cows = new cow[N];
	loopi(N)
		fin >> fences[i].x1 >> fences[i].y1 >> fences[i].x2 >> fences[i].y2;
	loopi(C)
		fin >> cows[i].x >> cows[i].y;
	// process
	// I give up...
	// output
	fout << C << endl;
	// cleanup
	fin.close();
	fout.close();
	delete[] fences;
	delete[] cows;
	return 0;
}