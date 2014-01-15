/*
ID: victor4
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct account{
	string name;
	int money;
};

account *findAccount(string name, account *accounts, int max){
	for(int i = 0; i < max; ++i)
		if(accounts[i].name == name)
			return &accounts[i];
	return NULL;
}

int main() {
	ofstream fout ("gift1.out");
	ifstream fin ("gift1.in");
	
	int NP;
	fin >> NP;
	#define loopa for(int i = 0; i < NP; ++i)
	
	account *accounts = new account[NP];
	loopa{
		fin >> accounts[i].name;
		accounts[i].money = 0;
	}
	
	string in = "";
	while(fin >> in){
		account *giver = findAccount(in, accounts, NP);
		if(giver == NULL){
			fout << "invalid";
			return 1;
		}
		int amount, recv;
		fin >> amount >> recv;
		
		int each = recv ? (amount / recv) : 0;
		int extra = recv ? (amount % recv) : amount;
		giver->money += extra - amount;
		
		for(int j = 0; j < recv; ++j){
			fin >> in;
			account *reciever = findAccount(in, accounts, NP);
			if(reciever != NULL)
				reciever->money += each;
		}
	}
	
	loopa{
		fout << accounts[i].name << " " << accounts[i].money << endl;
	}
	
	delete[] accounts;
	
	return 0;
}