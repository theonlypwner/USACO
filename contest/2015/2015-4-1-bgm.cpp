#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// # of combinations - # not a multiple of 7 = # multiple of 7
// It is not a multiple of 7 iff each term is not a multiple of 7

// (B+E+S+S+I+E)(G+O+E+S)(M+O+O)
// (M+2O)(G+O+(E+S))(B+I+2(E+S))

int main()
{
    ofstream fout("bgm.out");
    ifstream fin("bgm.in");

    int c[256] = {};
    int v[256][500];

    int N;
    fin >> N;

    for (int i = 0; i < N; ++i)
    {
        char var;
        int value;
        fin >> var >> value;
        v[var][c[var]++] = value;
    }

    const long long total = (long long)c['B'] * c['E'] * c['S'] * c['I'] * c['G'] * c['O'] * c['M'];
    long long total_invalid = 0;

    // First term: (M+2O)
    for (int i = 0; i < c['M']; ++i)
    {
        const int M = v['M'][i];
        for (int j = 0; j < c['O']; ++j)
        {
            const int O = v['O'][i];
            if ((M + 2 * O % 7) != 0)
            {
            }
        }
    }

    fout << total - total_invalid << endl;
    return 0;
}