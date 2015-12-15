#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout("cardgame.out");
    ifstream fin("cardgame.in");

    int N;
    vector<int> A, A1, A2;
    list<int> B;

    fin >> N;
    for (int i = 0; i < N; ++i) {
        int a;
        fin >> a;
        A.push_back(a);
        (i < (N >> 1) ? A1 : A2).push_back(a);
    }
    sort(A.begin(), A.end());
    sort(A1.begin(), A1.end());
    sort(A2.begin(), A2.end());
    A.push_back((N << 1) + 1);

    int j = 1;
    for (int i = 0; i <= N; ++i) {
        while (j < A[i]) {
            B.push_back(j);
            ++j;
        }
        ++j;
    }

    int score = 0;
    // use highest possible cards against highest possible card in first round
    for (auto i = A1.rbegin(); i != A1.rend(); ++i) {
        if (B.back() > *i) {
            B.pop_back();
            ++score;
            if (B.empty())
                goto DONE;
        }
    }
    // use lowest possible card against lowest possible card in the second round
    for (auto i = A2.begin(); i != A2.end(); ++i) {
        if (B.front() < *i) {
            B.pop_front();
            ++score;
            if (B.empty())
                break;
        }
    }

DONE:
    fout << score << endl;
    return 0;
}