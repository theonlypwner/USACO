#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

#define min3(a,b,c) min(min(a,b),c)

int solve(int T, int A, int B) {
    int n = T / A;
    int first_gap = (T % A) % B;
    int min_gap = first_gap, gap = first_gap;
    while (n--) {
        // Remove A and pad with B
        gap = (gap + A) % B;
        if (gap == first_gap)
            break; // % forms cycles
        min_gap = min(min_gap, gap);
    }
    return min_gap;
}

int main() {
    ofstream fout("feast.out");
    ifstream fin("feast.in");

    int T, A, B;
    fin >> T >> A >> B;

    if (A < B)
        swap(A, B);

    int min_remain = min3(
        solve(T - A / 2, A, B), // A < T
        solve(T - B / 2, A, B), // B < T
        solve(T, A, B));

    if (min_remain && A + B < T)
        min_remain = min(min_remain, solve(T - (A + B) / 2, A, B));

    fout << (T - min_remain) << endl;
    return 0;
}