#include <iostream>
#include <fstream>
 
#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i, x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)
 
using namespace std;

typedef unsigned short ushort;

#define GRIDSIZE 100
bool grid[GRIDSIZE][GRIDSIZE] = { { false } };

char adjacent_occupied(int x, int y){
	char ret = 0;
	if(x > 1){
		if(grid[x - 1][y]) ++ret;
	}
	if(x + 1 < GRIDSIZE){
		if(grid[x + 1][y]) ++ret;
	}
	if(y > 1){
		if(grid[x][y - 1]) ++ret;
	}
	if(y + 1 < GRIDSIZE){
		if(grid[x][y + 1]) ++ret;
	}
	return ret;
}

// optimized version of above for checking for a return of 4
bool adjacent_all_occupied(int x, int y){
	if(x <= 1 || x + 1 >= GRIDSIZE || y <= 1 || y + 1 >= GRIDSIZE) return false;
	return grid[x - 1][y] && grid[x + 1][y] && grid[x][y - 1] && grid[x][y + 1];
}

int main() {
	ofstream fout ("perimeter.out");
	ifstream fin ("perimeter.in");
	// get input
	int N;
	fin >> N;
	loopi(N){
		char x, y;
		fin >> x >> y;
		grid[x-1][y-1] = true;
	}
	// process
	ushort edges = 0;
	// fill holes
	loopi(GRIDSIZE)
		loopj(GRIDSIZE){
			if(!grid[i][j] && adjacent_all_occupied(i, j))
				grid[i][j] = true;
		}
	// count edges
	loopi(GRIDSIZE)
		loopj(GRIDSIZE)
			if(grid[i][j])
				edges += 4 - adjacent_occupied(i,j);
	// output
	fout << edges << endl;
	// cleanup
	fin.close();
	fout.close();
	return 0;
}