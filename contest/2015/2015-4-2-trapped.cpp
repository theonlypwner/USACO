#include <iostream>
#include <fstream>
#include <climits>
#include <algorithm>

using namespace std;

struct bale
{
    int size, position;

    static int compare(const void *a, const void *b)
    {
        return ((bale *)a)->position - ((bale *)b)->position;
    }
};

int N;
bale *bales;

int solve(int L, int r)
{
    if (L < 0 || r >= N)
        return INT_MAX;

    const int power = bales[r].position - bales[L].position;

    if (power > bales[L].size && power > bales[r].size)
        // remove any side
        return min(solve(L - 1, r), solve(L, r + 1));
    else if (power > bales[L].size)
        // remove left or block left
        return min(solve(L - 1, r), power - bales[L].size);
    else if (power > bales[r].size)
        // remove or block right
        return min(power - bales[r].size, solve(L, r + 1));
    else
        // trapped by default
        return 0;
}

int main()
{
    ofstream fout("trapped.out");
    ifstream fin("trapped.in");

    int B;
    fin >> N >> B;

    bales = new bale[N];
    for (int i = 0; i < N; ++i)
        fin >> bales[i].size >> bales[i].position;

    qsort(bales, N, sizeof(bale), bale::compare);

    int left, right = N;
    for (int i = 0; i < N; ++i)
        if (bales[i].position > B)
        {
            right = i;
            break;
        }
    left = right - 1;

    const int result = solve(left, right);

    fout << (result == INT_MAX ? -1 : result) << endl;
    return 0;
}