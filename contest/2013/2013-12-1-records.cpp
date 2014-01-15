#include <iostream>
#include <fstream>

#include <map>
#include <string>
#include <locale>

#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i, x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

locale l;
const collate<char>& coll = use_facet<std::collate<char> >(l);

int str_hash(string str){
	return coll.hash(str.data(), str.data() + str.length());
}

int main() {
	ofstream fout ("records.out");
	ifstream fin ("records.in");

	int N;
	fin >> N;

	int max_count = N ? 1 : 0;
	map<size_t, int> counts;

	loopi(N){
		string a, b, c;
		fin >> a >> b >> c;
		const int count = ++counts[str_hash(a) ^ str_hash(b) ^ str_hash(c)];
		if(count > max_count)
			max_count = count;
	}

	fout << max_count << endl;
	return 0;
}