#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <list>
#include <queue>
#include <functional>
#include <algorithm>
#include <climits>

using namespace std;

typedef tuple<int, int, int> interval_t;
typedef pair<int, int> interval_end_t;
typedef priority_queue<interval_end_t, vector<interval_end_t>, less<interval_end_t>> end_queue_t;

int main() {
    ofstream fout("haybales.out");
    ifstream fin("haybales.in");

    int N, Q;
    long long array[200000];
    list<interval_t> intervals;

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
                auto it = intervals.begin();
                while (it != intervals.end() && A > get<0>(*it))
                    ++it;
                intervals.insert(it, interval_t(A, B, C));
                break;
            }
            case 'S':
            {
                long long total = 0, extra = 0;
                auto it = intervals.begin();
                end_queue_t ends;
                for (int j = A; j <= B; ++j) {
                    while (it != intervals.end() && j >= get<0>(*it)) {
                        if (j <= get<1>(*it)) {
                            extra += get<2>(*it);
                            ends.push(interval_end_t(get<1>(*it), get<2>(*it)));
                        }
                        ++it;
                    }
                    while (!ends.empty() && j > ends.top().first) {
                        extra -= ends.top().second;
                        ends.pop();
                    }
                    total += array[j] + extra;
                }
                fout << total << '\n';
                break;
            }
            case 'M':
            {
                long long minimum = LLONG_MAX, extra = 0;
                auto it = intervals.begin();
                end_queue_t ends;
                for (int j = A; j <= B; ++j) {
                    while (it != intervals.end() && j >= get<0>(*it)) {
                        if (j <= get<1>(*it)) {
                            extra += get<2>(*it);
                            ends.push(interval_end_t(get<1>(*it), get<2>(*it)));
                        }
                        ++it;
                    }
                    while (!ends.empty() && j > ends.top().first) {
                        extra -= ends.top().second;
                        ends.pop();
                    }
                    minimum = min(minimum, array[j] + extra);
                }
                fout << minimum << '\n';
                break;
            }
        }
    }

    fout << flush;
    return 0;
}