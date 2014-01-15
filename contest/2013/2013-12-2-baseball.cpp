#include <iostream>
#include <fstream>

#include <algorithm>
#include <vector>

#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i, x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

int int_compare(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main() {
	ofstream fout ("baseball.out");
	ifstream fin ("baseball.in");
	// Read positions
	int N;
	fin >> N;
	int *positions = new int[N];
	loopi(N)
		fin >> positions[i];
	vector<int> p(positions, positions + N);
	// Sort positions
	sort(p.begin(), p.end());
	// Process the list
	int possibilities = 0;
	/*
	Find triples that match: a < b < c, (b-a) <= (c-b) <= 2(b-a)

	(b-a) <= (c-b): b - a <= c - b : 2b <= a + c
	a >= 2b - c
	b <= (a + c) / 2: b - a <= (c - a) / 2
	c >= 2b - a
	(c-b) <= 2(b-a): c - b <= 2b - 2a: c + 2a <= 3b
	a <= (3b-c)/2
	b >= (2a+c)/3: b - a >= (c - a) / 2
	c <= 3b - 2a

	a  b  c		a  b     c
	|--|--|  OR |--|-----|
	b - a must be within 1/3 and 1/2 of c - a
	*/
	loop_start(a, N - 2, 0){
		loop_start(c, N, a + 2){
			int min_index = lower_bound(p.begin(), p.end(), (2 * p[a] + p[c] + 2)/3) - p.begin(); // round up
			if(min_index <= a) continue;
			int max_index = upper_bound(p.begin(), p.end(), (p[a] + p[c]) / 2) - p.begin();
			if(max_index >= c) continue;
			possibilities += max_index - min_index + 1;
		}
	}
	fout << possibilities << endl;
	delete[] positions;
	return 0;
}