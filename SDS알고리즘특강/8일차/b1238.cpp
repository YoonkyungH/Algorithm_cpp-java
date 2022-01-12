// 파티
// 다익스트라 알고리즘

/**
 * 왔다 갔다 총 2번의 다익스트라를 돌렸음
 * 가는 길, 오는 길 총 2개 별개의 그래프를 생성해 따로 돌려줌
 * 그리고 dist(가는 거리) + dist2(돌아오는 거리)의 최댓값을 판별해 ans에 저장, 출력함
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 1001
#define INF 987654321

using namespace std;

struct Data {
    int node, weight;
    Data() {};
    Data(int node, int weight) : node(node), weight(weight) {};

    bool operator< (const Data d) const {   // 이 코드가 빠지면 안됨
        return weight > d.weight;
    }
};

int N, M, X;    // N명의 학생, M개의 도로, X번 마을에 모이기로 함
int s, e, t;    // 출발, 도착, 시간
priority_queue<Data> pq;
vector<Data> v[MAX];
vector<Data> v2[MAX];   // 돌아오는 루트
int dist[MAX];
int dist2[MAX]; // 돌아오는 거리
bool visited[MAX];
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X;

    for(int i=0; i<=N; i++) {   // 초기화
        v[i].clear();
        v2[i].clear();
        dist[i] = INF;
        dist2[i] = INF;
        visited[i] = false;
    }

    for(int i=0; i<M; i++) {
        cin >> s >> e >> t;
        v[s].push_back(Data(e, t)); // 단방향
        v2[e].push_back(Data(s, t)); // 역방향 (집에 오는 길 그래프를 따로 만들어놓는 것)
    }

    /**
     * 가는 길 다익스트라
     */
    dist[X] = 0;
    pq.push(Data(X, 0));

    while(!pq.empty()) {
        Data now = pq.top();
        pq.pop();

        if(visited[now.node]) continue;
        visited[now.node] = true;

        for(int i=0; i<v[now.node].size(); i++) {
            Data next = v[now.node].at(i);

            if(dist[next.node] > dist[now.node] + next.weight) {
                dist[next.node] = dist[now.node] + next.weight;
                pq.push(Data(next.node, dist[next.node]));
            }
        }
    }

    /**
     * 우선순위 큐, 기본적으로 배열을 초기화 시킨 후
     * 돌아오는 길 다익스트라 수행
     */
    for(int i=0; i<pq.size(); i++) { pq.pop(); }
    for(int i=0; i<=N; i++) {   // 초기화
        dist2[i] = INF;
        visited[i] = false;
    }

    dist2[X] = 0;
    pq.push(Data(X, 0));

    while(!pq.empty()) {
        Data now = pq.top();
        pq.pop();

        if(visited[now.node]) continue;
        visited[now.node] = true;

        for(int i=0; i<v2[now.node].size(); i++) {
            Data next = v2[now.node].at(i);

            if(dist2[next.node] > dist2[now.node] + next.weight) {
                dist2[next.node] = dist2[now.node] + next.weight;
                pq.push(Data(next.node, dist2[next.node]));
            }
        }
    }

    // 가는길 + 오는길 거리의 합으로 비교해 최댓값을 구함
    for(int i=1; i<=N; i++) {
        if(dist[i] < INF && dist2[i] < INF) ans = max(ans, (dist[i]+dist2[i]));
        else continue;
    }

    cout << ans << '\n';

    return 0;
}