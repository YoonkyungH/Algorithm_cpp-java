// 백도어
// 다익스트라로 안 풀면 시간초과
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 10000000001

int N, M;
vector<long long> dist;
int sight[100001];  // 시야
vector<vector<pair<int, int> > > v;
vector<bool> visited;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> sight[i];
    }

    v = vector<vector<pair<int, int> > >(N);
    for(int i=0; i<M; i++) {
        int a, b, t;
        cin >> a >> b >> t;

        v[a].push_back(make_pair(t, b));
        v[b].push_back(make_pair(t, a));
    }

    dist.resize(N);
    dist.assign(N, INF);
    visited.resize(N);
    visited.assign(N, false);

    priority_queue<pair<long long, int> > pq;

    dist[0] = 0;
    pq.push(make_pair(0, 0));

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if(visited[cur.second]) continue;

        visited[cur.second] = true;
        for(auto x : v[cur.second]) {
            if(!(sight[x.second] && x.second != N-1) && (dist[x.second] > dist[cur.second] + x.first)) {
                dist[x.second] = x.first + dist[cur.second];
                pq.push(make_pair(-dist[x.second], x.second));
            }
        }
    }

    if(dist[N-1] == INF) cout << "-1\n";
    else cout << dist[N-1] << '\n';

    return 0;
}