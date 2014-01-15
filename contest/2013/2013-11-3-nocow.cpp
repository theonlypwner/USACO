#include <iostream>
#include <fstream>

#include <set>
#include <string>

#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i, x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

int N, K;
#define N_MAX 10
#define MAXADJECTIVES 30
#define MAXADJECTIVELEN 10

const char *read_adjective(const char *in, char *out) {
	for(;;) {
		// Copy the last character
		if(*in == '\0' || *in == ' '){
			*out = '\0';
			return in + 1;
		}
		// Copy a character
		*out++ = *in++;
	}
}

int main() {
	ofstream fout ("nocow.out");
	ifstream fin ("nocow.in");
	// get input
	// Farmer John has no ___ cow. (19 + ___ + 5 + NULL)
	char linebuffer[19 + MAXADJECTIVES * MAXADJECTIVELEN + (MAXADJECTIVES-1) + 5 + 1];
	fin.getline(linebuffer, sizeof(linebuffer)/sizeof(*linebuffer));
	sscanf(linebuffer, "%d %d", &N, &K);
	--K; // convert to zero-based
	set<string> adjectives[MAXADJECTIVES];
	int num_adjectives = 0;
	string *removals[N_MAX];
	loopi(N) {
		fin.getline(linebuffer, sizeof(linebuffer)/sizeof(*linebuffer));
		const char *p = &linebuffer[19]; // skip "Farmer John has no "
		char adjective[11];
		if(!i) {
			removals[i] = new string[MAXADJECTIVES];
			loopj(MAXADJECTIVES){
				p = read_adjective(p, adjective);
				if(!strcmp(adjective, "cow."))
					break;
				++num_adjectives;
				adjectives[j].insert(adjective);
				removals[i][j] = adjective;
			}
		}
		else{
			removals[i] = new string[num_adjectives];
			loopj(num_adjectives) {
				p = read_adjective(p, adjective);
				adjectives[j].insert(adjective);
				removals[i][j] = adjective;
			}
		}
	}
	// calculate positions of the removals and adjust K if needed
	int offset = 0;
	int multipliers[N_MAX];
	loopi(N){
		int position = 0;
		multipliers[num_adjectives - 1] = 1;
		loop_rev(j, num_adjectives - 2, 0){
			multipliers[j] = multipliers[j + 1] * adjectives[j + 1].size();
		}
		loopj(num_adjectives)
			position += distance(adjectives[j].begin(), adjectives[j].find(removals[i][j])) * multipliers[j];
		if(position <= K)
			++offset;
	}
	K += offset;
	// Write output (Kth permutation)
	loopi(num_adjectives){
		if(i)
			fout << " ";
		set<string>::iterator it = adjectives[i].begin();
		advance(it, (K / multipliers[i]) % adjectives[i].size());
		fout << *it;
	}
	// Clean up
	loopi(N)
		delete[] removals[i];
	return 0;
}