#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout("highcard.out");
    ifstream fin("highcard.in");

    int N, A[50001];

    fin >> N;
    for (int i = 0; i < N; ++i)
        fin >> A[i];
    sort(A, A + N);
    A[N] = (N << 1) + 1;

    int E_prev = A[0], beatable = 1, score = 0;
    for (int i = 1; i <= N; ++i) {
        int gap = A[i] - A[i-1] - 1;
        if (gap > beatable) {
            score += beatable;
            beatable = 0;
        } else {
            score += gap;
            beatable -= gap;
        }
        ++beatable;
    }
    fout << score << endl;
    return 0;
}