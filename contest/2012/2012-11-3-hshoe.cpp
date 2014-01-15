#include <iostream>
#include <fstream>
#include <string>

#define loopi(x) loopi_start(x,0)
#define loopi_start(x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

int N, first_max;

int maxlen(string str, int pos, int first = 0, int second = 0, bool starting = true){
	if(starting && str[pos] != ')'){
		if(str[pos] == '('){
			if(++first > N * N / 2) return 0; // too long
		}
		else return 0; // fail (already there)
	}
	else{
		if(str[pos] != ')') return 0; // fail
		if(++second >= first) return first + second; // completed path
		starting = false;
	}
	// keep going
	str[pos] = ' ';
	int best = 0;
	// left
	if(pos % N) best = max(best, maxlen(str, pos - 1, first, second, starting));
	// right
	if(pos % N < N - 1 && pos < N * N - 1) best = max(best, maxlen(str, pos + 1, first, second, starting));
	// up
	if(pos >= N) best = max(best, maxlen(str, pos - N, first, second, starting));
	// down
	if(pos < N * (N - 1) - 1) best = max(best, maxlen(str, pos + N, first, second, starting));
	return best;
}

int main() {
	ofstream fout ("hshoe.out");
	ifstream fin("hshoe.in");
	// get input
	fin >> N;
	first_max = N * N / 2; // and it is truncated down anyways
	string str;
	loopi(N){
		string tmp;
		fin >> tmp;
		str += tmp;
	}
	// process
	int max_length = maxlen(str, 0);
	// output
	fout << max_length << '\n';
	// cleanup
	fin.close();
	fout.close();
	return 0;
}