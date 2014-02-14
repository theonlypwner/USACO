#include <iostream>
#include <fstream>

#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i,x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

int N, M; // [1, 1000]
int num_mirrors, max_depth;
char *grid;

// + = right and down
int length(int x, int y, char dx, char dy)
{
	int pos = x + y * M;
	int depth = 1;
	for(;;)
	{
		// Loop limit
		if(depth > max_depth) return -1;
		// Bounce
		if(grid[pos] == '/')
		{
			if(dy) { dx = -dy; dy = 0; }
			else   { dy = -dx; dx = 0; }
		}
		else // '\'
		{
			if(dy) { dx = +dy; dy = 0; }
			else   { dy = +dx; dx = 0; }
		}
		// Check if it leaves the board
		if(dy)
		{
			if(dy > 0) // down
			{
				++y;
				if(y >= N)
					return depth;
				pos += M;
			}
			else // up
			{
				//if(y - 1 < 0) -> (y < 1) -> y <= 0
				if(!y)
					return depth;
				--y;
				pos -= M;
			}
		}
		else
		{
			if(dx > 0) // right
			{
				++x;
				if(x >= M)
					return depth;
				++pos;
			}
			else // left
			{
				//if(x - 1 < 0) -> (x < 1) -> (x <= 0)
				if(!x)
					return depth;
				--x;
				--pos;
			}
		}
		// Continue the loop
		++depth;
	}
	return depth;
}

int best_path(){
	int longest = 0;
#define test(a, b, c, d) { \
		int result = length(a, b, c, d); \
		if(result == -1) return -1; \
		else if(result > longest) \
			longest = result; \
	}
	// Top
	loopi(M) test(i,     0,      0, +1)
	// Bottom
	loopi(M) test(i,     N - 1,  0, -1)
	// Left
	loopi(N) test(0,     i,     +1,  0)
	// Right
	loopi(N) test(N - 1, i,     -1,  0)
	return longest;
}

int main() {
	ofstream fout ("mirror.out");
	ifstream fin ("mirror.in");
	// Read input
	fin >> N >> M;
	num_mirrors = N * M;
	max_depth = num_mirrors << 1; // some mirrors can be reflected on their back side
	grid = new char[num_mirrors];
	loopi(num_mirrors)
		fin >> grid[i];
	// Calculate output
	fout << best_path() << endl;
	return 0;
}
