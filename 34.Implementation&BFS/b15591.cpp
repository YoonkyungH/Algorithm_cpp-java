// MooTube (Silver)
// BFS

#include <iostream>
#include <vector>
#include <queue>
#include <string.h> // memset
using namespace std;

int N, Q;
int p, q;
long long r;
long long k;
int v;

vector<vector<pair<int, long long> > > graph;   // 간선 저장

void BFS(long long k, int v) {  // k값, 동영상 v
    bool visited[5001] = {false, };
    visited[v] = true;

    queue<pair<int, long long> > q;
    q.push(make_pair(v, k));
    // q.push({v, k});
    
    int cnt = 0;

    while(!q.empty()) {
        int cur = q.front().first;
        int curVal = q.front().second;
        q.pop();

        for(int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nextVal = graph[cur][i].second;

            if(!visited[next] && nextVal >= k) {
                // 방문하지 않았으며 기준값 k 이상일 때 
                visited[next] = true;
                cnt++;

                q.push(make_pair(next, nextVal));
                // q.push({next, nextVal});
            }
        }
    }

    cout << cnt << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    graph.assign(N+1, vector<pair<int, long long> >(0, make_pair(0, 0)));
    for(int i=0; i<N-1; i++) {
        cin >> p >> q >> r;

        graph[p].push_back(make_pair(q, r));
        graph[q].push_back(make_pair(p, r));
        // graph[p].__emplace_back(make_pair(q, r));
        // graph[q].__emplace_back(make_pair(p, r));
    }

    while(Q--) {
        cin >> k >> v;
        BFS(k, v);
    }

    return 0;
}