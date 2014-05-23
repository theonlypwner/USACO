#include <iostream>
#include <fstream>

#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i,x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

int main() {
	ofstream fout ("lazy.out");
	ifstream fin ("lazy.in");
	int N, K;
	fin >> N >> K;
	int *grid = new int [N * N];
	memset(grid, 0, N*N*sizeof(int));
	loopi(N)
		loopj(N)
		{
			int value;
			fin >> value;
			loop_start(x, min(i+K+1,N), max(0, i-K))
			{
				int steps_used = abs(i - x);
				loop_start(y, min(j+K+1-steps_used,N), max(0, j-K+steps_used))
				{
					grid[x * N + y] += value;
				}
			}
		}
	int maximum_value = 0;
	loopi(N)
		loopj(N)
			if(grid[i * N + j] > maximum_value)
				maximum_value = grid[i * N + j];
	fout << maximum_value << endl;
	return 0;
}
