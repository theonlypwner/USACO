#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> coord;

map<coord, vector<coord>> switches;
bool on[100][100] = { { 0 } }, visited[100][100] = { { 0 } };
vector<coord> targets;

void visit(int x, int y) {
    // visit room
    visited[x][y] = 1;
    auto &new_targets = switches[make_pair(x, y)];
    for (auto j = new_targets.begin(); j != new_targets.end(); ++j)
        if (!on[j->first][j->second]) {
            on[j->first][j->second] = 1;
            targets.push_back(make_pair(j->first, j->second));
        }
}

int main() {
    ofstream fout("lightson.out");
    ifstream fin("lightson.in");
    int N, M;

    fin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int x, y, a, b;
        fin >> x >> y >> a >> b;
        switches[make_pair(x - 1, y - 1)].push_back(make_pair(a - 1, b - 1));
    }

    on[0][0] = 1;
    visit(0, 0);

    auto i = targets.begin();
    while (i != targets.end()) {
        const bool accessible =
            (i->first != 0 && visited[i->first - 1][i->second]) ||
            (i->second != 0 && visited[i->first][i->second - 1]) ||
            (i->first != N - 1 && visited[i->first + 1][i->second]) ||
            (i->second != N - 1 && visited[i->first][i->second + 1]);
        if (accessible) {
            int x = i->first, y = i->second;
            targets.erase(i);
            visit(x, y);
            i = targets.begin();
        }
        else
            ++i;
    }

    int total_on = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            total_on += on[i][j];

    fout << total_on << endl;
    return 0;
}