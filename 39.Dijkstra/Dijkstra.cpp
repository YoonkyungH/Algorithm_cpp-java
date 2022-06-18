// 다익스트라 알고리즘 기본 뼈대 코드
// 시간복잡도: O(N^2)로 느린편 -> 우선순위 큐를 사용하면 시간 단축 가능
// N: 정점의 수

// 우선순위 큐를 활용해 시간 복잡도를 낮춤  (dijkstra_heap() 함수)
// 시간복잡도: O(E * logN)
// E: 간선의 수 N: 정점의 수

#include <iostream>
#include <vector>
#include <queue>    // priority_queue
using namespace std;

#define tmp 11
#define INF 987654321

int dist[tmp];
int map[tmp][tmp];
bool visited[tmp] = {false, };

int start, end;

void dikstra_priority_queue() {
    vector<pair<int, int> > map[tmp];

    priority_queue<pair<int, int> > pq; // priority_queue: 값이 클수록 더 높은 우선순위를 가짐 (따라서 아래에서 - 를 붙여 반대로 만드는 것)
    // priority_queue<int, vector<int>, greater<int> > pq;  // 참고) 이렇게 선언하면 최소힙으로 구현 가능
    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int cost = -pq.top().first; // -를 붙이는 이유는 최소힙으로 구현하기 위함 (3, 2, 1 -> 1, 2, 3)
        int cur = pq.top().second;
        pq.pop();

        for(int i=0; i<map[cur].size(); i++) {
            int next = map[cur][i].first;
            int nextCost = map[cur][i].second;

            if(dist[next] > cost + nextCost) {
                dist[next] = cost + nextCost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }

    // 출력
    for(int i=1; i<=tmp; i++) {
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}

int find_shortest_node() {  // 2. 최단 거리 정점 찾기
    int min_dist = INF;
    int min_idx = -1;

    for(int i=1; i<=tmp; i++) {
        if(visited[i]) continue;    // 이미 방문했다면 continue
        if(dist[i] < min_dist) {    // 방문한 정점들과 직접적으로 연결된 노드만 해당 if문을 타게 되어있음 (직접 연결X->dist[]=INF일 것)
            min_dist = dist[i];
            min_idx = i;
        }
    }

    return min_idx;
}

void update_dist(int node) { // 3. 갱신
    for(int i=1; i<=tmp; i++) {
        if(visited[i]) continue;    // 이미 방문했다면 continue
        if(dist[i] > dist[node] + map[node][i]) {   // 새로 측정한 거리가 더 짧다면 갱신
            dist[i] = dist[node] + map[node][i];    
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /**
     * 1. 시작 노드와 직접적으로 연결된 모든 정점들의 거리를 비교해 업데이트, 시작노드를 방문 표시
     */
    for(int i=1; i<=tmp; i++) {
        dist[i] = map[start][i];
    }
    dist[start] = 0;    // 시작 노드와 자기 자신은 거리가 0이므로 갱신
    visited[start] = true; // 시작 노드의 방문 여부를 갱신

    /**
     * 2. 방문한 정점들과 연결된 정점 중 비용이 최소인 정점을 선택해 방문 표시
     * int min_idx = find_shortest_node();
     */

    /**
     * 3. 2 과정에 의해 갱신 가능한 정점들의 거리를 갱신
     * update_dist(min_idx);
     */

    // 2-3번 과정 (N(정점)-1 만큼 과정을 반복하게 됨)
    for(int i=0; i<tmp-1; i++) {
        int node = find_shortest_node();

        visited[node] = true;
        update_dist(node);
    }

    return 0;
}