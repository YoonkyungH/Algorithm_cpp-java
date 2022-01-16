// 최단경로
// 다익스트라 알고리즘
// parent배열로 어디로부터 왔을 때 최단경로였는지를 저장 (즉, 갱신되었을 때 저장해주는)

#include <iostream>
#include <queue>
#include <vector>

#define MAX 20002
#define INF 987654321

struct Data {
    int node, weight;
    Data() {};
    Data(int node, int weight) : node(node), weight(weight) {};

    // 오름차순 정렬
    bool operator<(const Data d) const {
        return weight > d.weight;
    }
};

using namespace std;

int V, E, start;
int u, v, w;
priority_queue<Data> pq;
vector<Data> vd[MAX];
int dist[MAX];
bool visited[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;  // 노드, 간선
    cin >> start;

    for(int i=0; i<=V; i++) {   
        vd[i].clear();
        dist[i] = INF;
        visited[i] = false;
    }

    for(int i=0; i<E; i++) {
        cin >> u >> v >> w;
        vd[u].push_back(Data(v, w));
    }

    dist[start] = 0;
    pq.push(Data(start, 0));

    while(!pq.empty()) {
        Data now = pq.top();
        pq.pop();

        if(visited[now.node]) continue;
        visited[now.node] = true; 

        for(int i=0; i<vd[now.node].size(); i++) {
            Data next = vd[now.node].at(i);

            if(dist[next.node] > dist[now.node] + next.weight) {
                dist[next.node] = dist[now.node] + next.weight;
                pq.push(Data(next.node, dist[next.node]));
            }
        }
    }

    for(int i=1; i<=V; i++) {
        if(dist[i] < INF)  cout << dist[i] << '\n';
        else cout << "INF\n";
    }

    return 0;
}