#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 최단경로
// 시간초과

int V, E, K; // 정점의 수, 간선의 수, 시작 정점 번호
int INF = 10000000;

vector<pair<int, int>> a[20001];  // 간선 정보를 담을 vector
int d[20001]; // 최소 거리를 넣을 배열

void dijkstra(int start) {
  d[start] = 0;
  // 가까운 순서대로 처리하므로 큐 사용. 또한 시간 복잡도를 줄임
  priority_queue<pair<int, int>> pq;
  pq.push(make_pair(start, 0));

  while(!pq.empty()) {
    int current = pq.top().first;       // 현재 위치를 current에 저장
    int distance = -pq.top().second;    // 거리 짧은 것이 먼저 오도록 음수화시킴
    pq.pop();

    if(d[current] < distance) continue; // 최단거리가 아닐 경우 스킵
    for(int i=0; i<a[current].size(); i++) {
      // 선택된 노드의 인접 노드
      int next = a[current][i].first;
      // 선택된 노드를 인접 노드로 거쳐 가는 비용
      int nextDistance = distance + a[current][i].second;
      // 기존 최소 거리보다 짧다면 갱신
      if(nextDistance < d[next]) {
        d[next] = nextDistance;
        pq.push(make_pair(next, -nextDistance));
      }
    }
  }
}

int main() {

  scanf("%d %d %d", &V, &E, &K);
  // cin >> V >> E;
  // cin >> K;

  for(int i=1; i<=V; i++) {
    d[i] = INF;
  }

  while(E--) {
    int u, v, w;  // 출발, 도착, 거리

    scanf("%d %d %d", &u, &v, &w);
    // cin >> u >> v >> w;
    a[u].push_back(make_pair(v, w));
  }

  dijkstra(K);

  for(int i=1; i<=V; i++) {
    if(d[i] == INF) printf("INF\n");
    else printf("%d\n", d[i]);
  }
}
