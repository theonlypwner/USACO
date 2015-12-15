#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct accum_t {
    int c[3];
} accum[100001] = { { 0, 0, 0 } };

int main() {
    ofstream fout("bcount.out");
    ifstream fin("bcount.in");
    int N, Q;
    fin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        accum[i + 1] = accum[i];
        int b;
        fin >> b;
        ++accum[i + 1].c[b - 1];
    }
    for (int i = 0; i < Q; ++i) {
        int a, b;
        fin >> a >> b;
        fout
            << accum[b].c[0] - accum[a - 1].c[0] << ' '
            << accum[b].c[1] - accum[a - 1].c[1] << ' '
            << accum[b].c[2] - accum[a - 1].c[2] << '\n';
    }
    fout << flush;
    return 0;
}