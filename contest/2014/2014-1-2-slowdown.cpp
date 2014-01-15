#include <iostream>
#include <fstream>

#include <algorithm>

#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i, x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

int main() {
	ofstream fout ("slowdown.out");
	ifstream fin ("slowdown.in");
	// Read input
	short N; // [1, 10000]
	fin >> N;
	short D = 0, T = 0;
	short *event_d = new short[N];
	short *event_t = new short[N];
	loopi(N){
		char event_type;
		int num;
		fin >> event_type >> num;
		if(event_type == 'D'){
			event_d[D++] = num;
		}
		else{ //if(event_type == 'T')
			event_t[T++] = num;
		}
	}
	// Calculate output
	// sort events O(N log N)
	sort(event_d, event_d + D);
	sort(event_t, event_t + T);
	double total_time = 0, total_dist = 0;
	short speedr = 1;
	short D_cur = 0, T_cur = 0;
	// trace time usage
	for(;;){
		// adjust for the next event
		if(D_cur < D){
			if(T_cur < T && event_t[T_cur] < total_time + (event_d[D_cur] - total_dist) * speedr)
				goto ADJUST_TIME;
ADJUST_DIST:
			total_time += (event_d[D_cur] - total_dist) * speedr;
			total_dist = event_d[D_cur++];
			++speedr;
		}
		else if(T_cur < T){
ADJUST_TIME:
			total_dist += (event_t[T_cur] - total_time) / speedr;
			total_time = event_t[T_cur++];
			++speedr;
		}
		else{
			// no more events
			total_time += (1000 - total_dist) * speedr;
			break;
		}
	}
	fout << total_time << endl;
	return 0;
}