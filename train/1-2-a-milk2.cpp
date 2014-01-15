/*
ID: victor4
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

#include <algorithm>
#include <vector>

using namespace std;

/*
template <class T>
inline T max(T a, T b){
	return a > b ? a : b;
}
*/

struct timespan{
	int start, end;
	bool operator < (const timespan &t) const{
		return start < t.start;
	}
};

int main() {
	ofstream fout ("milk2.out");
	ifstream fin ("milk2.in");
	
	int N;
	fin >> N;
	
	// store into vector
	vector<timespan> actives;
	for(int i = 0; i < N; ++i){
		int start, end;
		fin >> start >> end;
		
		timespan new_timespan;
		new_timespan.start = start;
		new_timespan.end = end;
		actives.push_back(new_timespan);
	}
	
	// remove overlap
	sort(actives.begin(), actives.end());
	for(vector<timespan>::size_type i = 1; i < actives.size(); ++i)
		// failure here for using < instead of <=
		if(actives[i].start <= actives[i - 1].end){
			// overlap
			actives[i - 1].end = max(actives[i].end, actives[i - 1].end);
			actives.erase(actives.begin() + (i--));
		}
	
	// get maximum (in)active time
	
	int max_active = 0;
	// failure 1: 0-first hours are not "inactive"
	//int max_inactive = actives.front().start;
	int max_inactive = 0;
	
	for(vector<timespan>::size_type i = 0; i < actives.size(); ++i){
		// active time
		// (e - s > m) -> (e > s + m)
		if(actives[i].end > actives[i].start + max_active)
			max_active = actives[i].end - actives[i].start;
		if(!i)
			continue;
		const int span = actives[i].start - actives[i - 1].end;
		if(span > max_inactive)
			max_inactive = span;
	}
	
	fout << max_active << " " << max_inactive << endl;
	return 0;
}