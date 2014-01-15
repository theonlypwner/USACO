/*
ID: victor4
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAXCOSTS 1001

int main() {
	ofstream fout ("milk.out");
	ifstream fin ("milk.in");
	
	int req, farmers;
	fin >> req >> farmers;
	
	int available[MAXCOSTS] = {0};
	for(int i = 0; i < farmers; ++i){
		int price, amt;
		fin >> price >> amt;
		available[price % MAXCOSTS] += amt;
	}
	
	int cost = 0;
	for(int i = 0; i < MAXCOSTS; ++i){
		if(available[i]){
			if(available[i] >= req){
				cost += i * req;
				break;
			}
			else{
				cost += i * available[i];
				req -= available[i];
			}
		}
	}
	
	fout << cost << endl;
	return 0;
}