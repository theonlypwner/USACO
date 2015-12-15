#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int N, M;
char grid[1000][1000];

#define INF 20000000
int dist[1000][1000][2];
struct p {
    int x, y, z;
    bool operator <(const p& rhs) const
    {
        if (x != rhs.x)
            return x < rhs.x;
        else if (y != rhs.y)
            return y < rhs.y;
        else
            return z < rhs.z;
    }
};
typedef pair<int, p> vp;
priority_queue<vp, vector<vp>, greater<vp>> pq;

inline bool ok(char c) { return c && c != 3; }

void relax(const p cur, int dst, int dx, int dy) {
    int x = cur.x + dx;
    int y = cur.y + dy;
    int z = cur.z;
    int travelled = 1;
    switch (grid[x][y]) {
    case 0:
        return;
    case 1:
        break;
    case 2:
        z = 1;
        break;
    case 3:
        if (!z)
            return;
        break;
    case 4:
        if (dx > 0) {
            while (grid[x][y] == 4 && x + 1 != N && ok(grid[x + 1][y])) {
                ++x;
                ++travelled;
            }
        }
        else if (dx < 0) {
            while (grid[x][y] == 4 && x && ok(grid[x - 1][y])) {
                --x;
                ++travelled;
            }
        }
        else if (dy > 0) {
            while (grid[x][y] == 4 && y + 1 != M && ok(grid[x][y + 1])) {
                ++y;
                ++travelled;
            }
        }
        else {
            while (grid[x][y] == 4 && y && ok(grid[x][y - 1])) {
                --y;
                ++travelled;
            }
        }
        z = 0;
        break;
    }
    int alt = dst + travelled;
    if (alt < dist[x][y][z])
        pq.push(vp((dist[x][y][z] = alt), { x, y, z }));
}

int main() {
    ofstream fout("dream.out");
    ifstream fin("dream.in");

    fin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            int x;
            fin >> x;
            grid[i][j] = x;
        }

    // Dijkstra with heap
    for (int x = 0; x < N; ++x)
        for (int y = 0; y < M; ++y) {
            dist[x][y][0] = dist[x][y][1] = INF;
        }
    dist[0][0][0] = 0;

    pq.push(vp(0, { 0, 0, 0 }));
    while (pq.size()) {
        int dst = pq.top().first;
        p cur = pq.top().second;
        pq.pop();
        // Visit neighbors of u
        //visited[ux][uy][uz] = true;
        if (cur.x)
            relax(cur, dst, -1, 0);
        if (cur.y)
            relax(cur, dst, 0, -1);
        if (cur.x + 1 != N)
            relax(cur, dst, 1, 0);
        if (cur.y + 1 != M)
            relax(cur, dst, 0, 1);
    }

    int shortest = min(dist[N - 1][M - 1][0], dist[N - 1][M - 1][1]);

    if (shortest == INF)
        shortest = -1;

    fout << shortest << endl;
    return 0;
}