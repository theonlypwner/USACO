#include <iostream>
#include <fstream>
#include <algorithm>

#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i,x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

int main() {
	ofstream fout ("mooomoo.out");
	ifstream fin ("mooomoo.in");
	int N, B;
	fin >> N >> B;
	int *breeds = new int[B];
    loopi(B)
        fin >> breeds[i];
    sort(breeds, breeds + B);
	// 
	fout << maximum_value << endl;
	return 0;
}
