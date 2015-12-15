#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ofstream fout("haybales.out");
    ifstream fin("haybales.in");

    int N, Q;
    long long array[200000];

    fin >> N >> Q;

    for (int i = 0; i < N; ++i)
        fin >> array[i];

    for (int i = 0; i < Q; ++i) {
        char type;
        int A, B;
        fin >> type >> A >> B;
        --A, --B;
        switch (type) {
            case 'P':
            {
                int C;
                fin >> C;
                for (int j = A; j <= B; ++j)
                    array[j] += C;
                break;
            }
            case 'S':
            {
                long long total = 0;
                for (int j = A; j <= B; ++j)
                    total += array[j];
                fout << total << '\n';
                break;
            }
            case 'M':
            {
                long long minimum = LLONG_MAX;
                for (int j = A; j <= B; ++j)
                    if(array[j] < minimum)
                        minimum = array[j];
                fout << minimum << '\n';
                break;
            }
        }
    }

    fout << flush;
    return 0;
}