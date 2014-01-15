#include <iostream>
#include <fstream>

#include <algorithm>
#include <string>
 
#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i, x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)
 
using namespace std;

struct nameinfo
{
	string lowest;
	string highest;

	nameinfo() : lowest(""), highest("") { }
};

int nameinfo_compare_min(const void *a, const void *b){
	return (*(const nameinfo **)a)->lowest.compare((*(const nameinfo **)b)->lowest);
}

int nameinfo_compare_max(const void *a, const void *b){
	return (*(const nameinfo **)a)->highest.compare((*(const nameinfo **)b)->highest);
}

int main() {
	ofstream fout ("scramble.out");
	ifstream fin ("scramble.in");
	// get input
	unsigned int N;
	fin >> N;
	// more input, but with processing
	nameinfo *names = new nameinfo[N], **names_min = new nameinfo*[N], **names_max = new nameinfo*[N];
	loopi(N){
		fin >> names[i].lowest;
		// sort string
		sort(names[i].lowest.begin(), names[i].lowest.end());
		// reverse of sorted string
		names[i].highest = string(names[i].lowest.rbegin(), names[i].lowest.rend());
		names_min[i] = &names[i];
		names_max[i] = &names[i];
	}
	// process
	qsort(names_min, N, sizeof(nameinfo*), nameinfo_compare_min);
	qsort(names_max, N, sizeof(nameinfo*), nameinfo_compare_max);
	// output
	loopi(N){
		// finding the same string might waste time?
		int min_pos = N - 1, max_pos = N - 1;
		loopj(N)
			if(names_min[j] == &names[i]){
				min_pos = j;
				break;
			}
		loopj(N)
			if(names_max[j] == &names[i]){
				max_pos = j;
				break;
			}
			if(min_pos > max_pos){
				int temp = min_pos;
				min_pos = max_pos;
				max_pos = temp;
			}
		fout << min_pos + 1 << ' ' << max_pos + 1 << endl;
	}
	// cleanup
	fin.close();
	fout.close();
	delete[] names;
	return 0;
}