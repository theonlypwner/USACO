#include <iostream>
#include <fstream>
#include <string>
 
#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i, x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)
 
using namespace std;

// a linked list of steps
/* I originally used a linked list, but I changed my idea
struct step {
	int move;
	step *next;
	step(int move) : move(move), next(NULL) {}
};
*/

int main() {
	ofstream fout ("greetings.out");
	ifstream fin ("greetings.in");
	// get input
	unsigned short B, E;
	fin >> B >> E;
	//int deltas[1000000] = { 0 };
	int *deltas = new int[1000000]; // it will end up as the difference in position between the two cows
	memset(deltas, 0, 1000000*sizeof(int));
	// get more input
	int pos = 0, total_b = 0, total_e = 0;
	loopi(B){ // fill with current position of B
		int num;
		char direction;
		fin >> num >> direction;
		loopj(num){
			deltas[pos] = (direction == 'R' ? -1 : 1);
			++pos;
		}
	}
	total_b = pos;
	pos = 0;
	loopi(E){
		int num;
		char direction;
		fin >> num >> direction;
		loopj(num){
			deltas[pos] += (pos ? deltas[pos - 1] : 0) - (direction == 'R' ? -1 : 1);
			++pos;
		}
	}
	total_e = pos;
	loop_start(i, total_b, total_e){
		deltas[i] += deltas[i - 1];
	}
	// process
	int meetings = 0;
	int total = total_e > total_b ? total_e : total_b;
	bool canmeet = false;
	loopi(total){
		if(!deltas[i]){
			if(canmeet){
				++meetings;
				canmeet = false;
			}
		}
		else canmeet = true;
	}
	// output
	fout << meetings << endl;
	// cleanup
	fin.close();
	fout.close();
	delete[] deltas;
	return 0;
}