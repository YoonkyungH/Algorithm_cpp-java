// 택배 배송
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int N, M;
vector<pair<int, int> > v[50001];
int dist[50001];

// 출발 지점이 1, 도착 지점이 N
void Dijkstra() {   // 우선순위 큐

    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, 1));

    dist[1] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(cost > dist[cur]) continue;

        for(int i=0; i<v[cur].size(); i++) {
            int next = v[cur][i].first;
            int nCost = cost + v[cur][i].second;

            if(nCost < dist[next]) {
                dist[next] = nCost;
                pq.push(make_pair(-nCost, next));
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    // dist INF 초기화
    for(int i=0; i<=N; i++) {
        dist[i] = INF;
    }

    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
 
    Dijkstra();

    cout << dist[N] << '\n';

    return 0;
}