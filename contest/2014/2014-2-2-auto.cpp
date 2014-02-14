#include <iostream>
#include <fstream>

#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i,x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

struct entry {
	int id;
	char *name;
	static int compare (const void* p1, const void* p2){
		return strcmp(((entry *) p1)->name, ((entry *) p2)->name);
	}
};

entry *entries;

bool startsWith(char *needle, char *haystack){
	for(; *needle; ++needle, ++haystack)
		if(*needle != *haystack)
			return false;
	return true;
}

int main() {
	ofstream fout ("auto.out");
	ifstream fin ("auto.in");
	// Read settings and dictionary
	int W, N;
	fin >> W >> N;
	int id = 1;
	entries = new entry[W];
	loopi(W){
		static char buf[1001];
		fin >> buf;
		int len = strlen(buf);

		entries[i].name = new char[len+1];
		memcpy(entries[i].name, buf, sizeof(char)*(len+1));

		entries[i].id = id++;
	}
	// Sort entries
	qsort(entries, W, sizeof(entry), entry::compare);
	// Process requests
	loopi(N){
		static char buf[1001];
		int pos = -1;
		int remain;
		fin >> remain >> buf;
		loopj(W){
			// early exit if we passed the first letter
			if(entries[j].name[0] > buf[0])
				break;
			if(startsWith(buf, entries[j].name)){
				--remain;
				if(!remain){
					pos = entries[j].id;
					break;
				}
			}
		}
		fout << pos << endl;
	}
	return 0;
}
