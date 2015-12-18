#include <iostream>
#include <fstream>
#include <string>
//#include <vector>
#include <algorithm>

using namespace std;

int N, M;
char grid[1000][1000];

#define INF 20000000
int dist[1000][1000][2];
bool visited[1000][1000][2] = { 0 };

inline bool ok(char c) { return c && c != 3; }

void relax(const int ux, const int uy, const int uz, int dx, int dy) {
    int x = ux + dx;
    int y = uy + dy;
    int z = uz;
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
            if (!uz)
                return;
            break;
        case 4:
            if (dx > 0) {
                while (x + 1 != N && ok(grid[x + 1][y])) {
                    ++x;
                    ++travelled;
                }
            } else if (dx < 0) {
                while (x && ok(grid[x - 1][y])) {
                    --x;
                    ++travelled;
                }
            } else if (dy > 0) {
                while (y + 1 != M && ok(grid[x][y + 1])) {
                    ++y;
                    ++travelled;
                }
            } else {
                while (y && ok(grid[x][y - 1])) {
                    --y;
                    ++travelled;
                }
            }
            z = 0;
            break;
    }
    int alt = dist[ux][uy][uz] + travelled;
    if (alt < dist[x][y][z])
        dist[x][y][z] = alt;
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

    // Dijkstra without heap
    for (int x = 0; x < N; ++x)
        for (int y = 0; y < M; ++y) {
            dist[x][y][0] = dist[x][y][1] = INF;
        }
    dist[0][0][0] = 0;

    const int numv = (M * N) << 1;
    for (int i = 0; i < numv; ++i) {
        // u = closest vertex
        int ux, uy, uz;
        bool force = true;
        for (int x = 0; x < N; ++x)
            for (int y = 0; y < M; ++y)
                for (int z = 0; z != 2; ++z) {
                    if (visited[x][y][z])
                        continue;
                    else if (force || dist[x][y][z] < dist[ux][uy][uz]) {
                        ux = x;
                        uy = y;
                        uz = z;
                        force = false;
                    }
                }

        // Visit neighbors of u
        visited[ux][uy][uz] = true;
        if (ux)
            relax(ux, uy, uz, -1, 0);
        if (uy)
            relax(ux, uy, uz, 0, -1);
        if (ux + 1 != N)
            relax(ux, uy, uz, 1, 0);
        if (uy + 1 != M)
            relax(ux, uy, uz, 0, 1);
    }

    int shortest = min(dist[N - 1][M - 1][0], dist[N - 1][M - 1][1]);

    if (shortest == INF)
        shortest = -1;

    fout << shortest << endl;
    return 0;
}