/*
ID: victor4
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <class T>
struct matrix{
	int sz;
	T **storage;
	
	matrix(int sz) : sz(sz){
		storage = new T*[sz];
		for(int i = 0; i < sz; ++i)
			storage[i] = new T[sz];
	}
	~matrix() {
		for(int i = 0; i < sz; ++i)
			delete[] storage[i];
		delete[] storage;
	}
	
	bool operator == (const matrix &t){
		for(int x = 0; x < sz; ++x)
			for(int y = 0; y < sz; ++y)
				if(storage[x][y] != t.storage[x][y])
					return false;
		return true;
	}
	
	void rot90(){ // clockwise
		T old[sz][sz];
		for(int x = 0; x < sz; ++x)
			for(int y = 0; y < sz; ++y)
				old[x][y] = storage[x][y];
		for(int x = 0; x < sz; ++x)
			for(int y = 0; y < sz; ++y)
				storage[x][y] = old[y][sz-1-x];
	}
	
	void reflect_h(){
		T old[sz][sz];
		for(int x = 0; x < sz; ++x)
			for(int y = 0; y < sz; ++y)
				old[x][y] = storage[x][y];
		for(int x = 0; x < sz; ++x)
			for(int y = 0; y < sz; ++y)
				storage[x][y] = old[x][sz-1-y];
	}
};

int main() {
	ofstream fout ("transform.out");
	ifstream fin ("transform.in");
	
	int N;
	fin >> N;
	
	// read matrices
	matrix<char> m1(N), m2(N);
	for(int x = 0; x < N; ++x){
		string in;
		fin >> in;
		for(int y = 0; y < N; ++y){
			m1.storage[x][y] = in[y];
		}
	}
	
	for(int x = 0; x < N; ++x){
		string in;
		fin >> in;
		for(int y = 0; y < N; ++y){
			m2.storage[x][y] = in[y];
		}
	}
	
	m1.rot90();
	if(m1 == m2)
		fout << 1;
	else{
		m1.rot90();
		if(m1 == m2)
			fout << 2;
		else{
			m1.rot90();
			if(m1 == m2)
				fout << 3;
			else{
				m1.rot90(); // back where we started!
				m1.reflect_h();
				if(m1 == m2)
					fout << 4;
				else{
					bool found = false;
					for(int i = 0; i < 3; ++i){
						m1.rot90();
						if(m1 == m2){
							found = true;
							fout << 5;
							break;
						}
					}
					if(!found){
						m1.rot90();
						fout << ((m1 == m2) ? 6 : 7);
					}
				}
			}
		}
	}
	
	fout << endl;
	return 0;
}