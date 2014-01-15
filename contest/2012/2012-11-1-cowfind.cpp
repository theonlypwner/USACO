#include <iostream>
#include <fstream>
#include <string>

#define loopi(x) loopi_start(x,0)
#define loopi_start(x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

int main() {
	ofstream fout ("cowfind.out");
	ifstream fin("cowfind.in");
	// get input
	string str;
	fin >> str;
	int locations = 0;
	//)((()())())
	loopi(str.length() - 3){
		if(str[i] == '(' && str[i + 1] == '('){
			loop_rev(j, str.length() - 1, i + 3){
				if(str[j] == ')' && str[j - 1] == ')')
					++locations;
			}
		}
	}
	// output
	fout << locations << '\n';
	// cleanup
	fin.close();
	fout.close();
	return 0;
}