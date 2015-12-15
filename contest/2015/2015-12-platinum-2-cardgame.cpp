#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
set<int> A1, A2, B;

int solve() {
    int score = 0;
    auto B2 = B.rbegin();
    // use highest possible cards against highest possible cards in first part
    for (auto i = A1.rbegin(); i != A1.rend(); ++i) {
        if (*B2 > *i) {
            ++score;
            if (++B2 == B.rend())
                return score;
        }
    }
    auto B1 = B.begin();
    // use lowest possible cards against lowest possible cards in the second part
    for (auto i = A2.begin(); i != A2.end(); ++i) {
        if (*B1 < *i) {
            ++score;
            if (*B1 == *B2)
                break;
            ++B1;
        }
    }
    return score;
}

int main() {
    ofstream fout("cardgame.out");
    ifstream fin("cardgame.in");

    fin >> N;
    for (int i = 0; i < N; ++i) {
        int a;
        fin >> a;
        A.push_back(a);
        A2.insert(a);
    }

    A2.insert((N << 1) + 1);
    int j = 1;
    for (auto i = A2.begin(); i != A2.end(); ++i) {
        while (j < *i)
            B.insert(j++);
        ++j;
    }
    A2.erase((N << 1) + 1);

    int score = solve();

    while (!A.empty()) {
        A2.erase(A.back());
        A1.insert(A.back());
        A.pop_back();
        score = max(score, solve());
    }

    fout << score << endl;
    return 0;
}