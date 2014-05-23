#include <iostream>
#include <fstream>

#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i,x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

struct cow {
	unsigned int pos;
	bool W;
	static int compare (const cow * a, const cow * b)
	{
		return a->pos - b->pos;
	}
};

int N;
cow *cows;

int max_span(unsigned int a, unsigned int b, unsigned int W, unsigned int S) {
	// there must be at least one W
	if(!W) return 0;
	if(W < S) {
		unsigned int surplus = S - W;
		do {
			if(!cows[a].W) {
				if(!cows[b].W && (cows[b].pos - cows[b-1].pos) < (cows[a+1].pos - cows[a].pos))
					goto USEB;
				++a;
				--surplus;
				continue;
			} else if(!cows[b].W) {
				USEB:
				--b;
				--surplus;
				continue;
			}
			break;
		} while(surplus);
		if(surplus)
			return max(max_span(a+1, b, W-1, S), max_span(a, b-1, W-1, S));
		return cows[b].pos - cows[a].pos;
	}
	else {
		if ((W & 1) == (S & 1))
			// solved!
			return cows[b].pos - cows[a].pos;
		else
			// remove left or right
			return max(cows[b-1].pos - cows[a].pos, cows[b].pos - cows[a+1].pos);
	}
}

int main() {
	ofstream fout ("fairphoto.out");
	ifstream fin ("fairphoto.in");
	fin >> N;
	cows = new cow[N];
	unsigned int W = 0, S = 0;
	loopi(N) {
		char type;
		fin >> cows[i].pos >> type;
		if((cows[i].W = (type == 'W'))) ++W;
		else ++S;
	}
	qsort(cows, N, sizeof(cow), (int (*) (const void * a, const void * b)) cow::compare);
	fout << max_span(0, N-1, W, S) << endl;
	return 0;
}
