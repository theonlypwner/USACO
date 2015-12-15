#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

#define MAXN 50000

int N, K, V[MAXN] = { 0 }, src[MAXN], max_vertex = 0;
map<int, vector<int>> edges;

inline void add(int s, int t) {
    queue<int> q;
    bool visited[MAXN] = { false };

    src[s] = -1;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == t) {
            do {
                if(++V[cur] > max_vertex)
                    max_vertex = V[cur];
                cur = src[cur];
            } while (cur != -1);
            break;
        }
        for (auto next : edges[cur]) {
            if (visited[next])
                continue;
            src[next] = cur;
            q.push(next);
            visited[next] = true;
        }
    }
}

int main() {
    ofstream fout("maxflow.out");
    ifstream fin("maxflow.in");

    fin >> N >> K;

    while (--N) {
        int x, y;
        fin >> x >> y;
        --x, --y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    while (K--) {
        int s, t;
        fin >> s >> t;
        --s, --t;
        add(s, t);
    }

    fout << max_vertex << endl;
    return 0;
}