// 최소비용 구하기
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321

int N, M;
int start, destination;
vector<pair<int, int> > v[1001];
priority_queue<pair<int, int> > pq;
int dist[1001];

void init() {
    for(int i=1; i<=N; i++) {
        dist[i] = INF;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;  // 도시, 버스
    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }

    cin >> start >> destination;

    init();

    pq.push(make_pair(0, start));
    dist[start] = 0;
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur] < cost) continue;  // 없으면 시간초과

        for(int i=0; i<v[cur].size(); i++) {
            int next = v[cur][i].first;
            int nCost = cost + v[cur][i].second;
            if(dist[next] > nCost) {
                dist[next]  = nCost;
                pq.push(make_pair(-nCost, next));
            }
        }
    }
    cout << dist[destination] << '\n';

    return 0;
}