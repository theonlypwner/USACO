#include <iostream>
#include <fstream>
#include <map>
#include <queue>

#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i,x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

int N, M, *best, *previous, *path;

struct road {
    int dest;
    int length1, length2;
    int cost;
    static int len1 (const road &r) { return r.length1; }
    static int len2 (const road &r) { return r.length2; }
    static int lencost (const road &r) { return r.cost; }
};

typedef multimap<int, road> roadmap;
roadmap roads;

void lowest_cost(int (*length) (const road &)) {
    // <dist, node>
    priority_queue<pair<int, int>> q;
    previous[1] = 0;
    q.push(make_pair(0, 1));
    do {
        int dist = q.top().first;
        int node = q.top().second;
        q.pop();
        if(best[node] <= dist)
            continue;
        best[node] = dist;
        pair<roadmap::iterator, roadmap::iterator> iters = roads.equal_range(node);
        for(roadmap::iterator it = iters.first; it != iters.second; ++it) {
            int nextdist = dist + length(it->second);
            if(nextdist < best[it->first] || best[it->first] < 0) {
                previous[it->first] = node;
                q.push(make_pair(nextdist, it->first));
            }
        }
        /*
        while PQ is not empty:                // The main loop
           u := PQ.extract_min()             // Remove and return best vertex
           for each neighbor v of u:         // where v has not yet been removed from PQ.
               alt = dist[u] + length(u, v) 
               if alt < dist[v]              // Relax the edge (u,v) 
                   dist[v] := alt 
                   previous[v] := u
                   PQ.decrease_priority(v,alt)
               end if
           end for
       end while
        */
    } while(!q.empty());
    int i = N;
    do {
        path[previous[i] - 1] = i - 1;
        i = previous[i];
    } while(i);
}

int main() {
	ofstream fout ("gpsduel.out");
	ifstream fin ("gpsduel.in");
	fin >> N >> M;
    best = new int[N+1];
    previous = new int[N+1];
    path = new int[N];
    loopi(M) {
        int src;
        road r;
        fin >> src >> r.dest >> r.length1 >> r.length2;
        r.cost = 2;
        roads.insert(make_pair(src, r));
    }
    lowest_cost(road::len1);
    int i = 0;
    do{
        pair<roadmap::iterator, roadmap::iterator> iters = roads.equal_range(i);
        for(roadmap::iterator it = iters.first; it != iters.second; ++it) {
            if(it->first == path[i]){
                --it->second.cost;
                break;
            }
        }
        i = path[i];
    } while(i != N - 1);
    lowest_cost(road::len2);
    lowest_cost(road::lencost);
	fout << 0 << endl;
	return 0;
}
