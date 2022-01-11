// 다익스트라 기본 뼈대 코드
// ***** 다익스트라 완전 중요 *****

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 987654321

struct Data {
    int node;
    int weight;
    Data() {};
    Data(int node, int weight) : node(node), weight(weight) {};

    // 오름차순 정렬
    bool operator<(const Data d) const {
        return weight > d.weight;
    }
};

using namespace std;

// 10은 참고로 문제에서는 최대 노드 개수만큼 설정
vector<Data> v[10];         // 다음에 방문할 노드, 가중치(priority_queue와 조금 다르긴 한데 여기서는 같이 쓰겠음)
int dist[10];   
bool isVisted[10];
priority_queue<Data> pq;    // 다음에 방문할 노드, 가중치

int N, M;
int a, b, c; // 이렇게 전역으로 선언해두는 것이 좋음

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0; i<=N; i++) {   // 초기화
        v[i].clear();
        dist[i] = INF;
        isVisted[i] = false;
    }

    for(int i=0; i<M; i++) {
        cin >> a >> b >> c; 
        v[a].push_back(Data(b, c)); // 단방향일 때는 이 줄만
        v[b].push_back(Data(a, c)); // 양방향일 때는 이렇게 양방향을 구현
    }

    dist[1] = 0;            // 1부터 시작한다고 생각했을 때 출발점을 0으로 초기화
    pq.push(Data(1, 0));    // "1에서 출발하며 그 값은 0이다."

    while(!pq.empty()) {
        Data now = pq.top();            // 지금 방문한 노드 = now
        pq.pop();
        if(isVisted[now.node]) continue; // 방문 했었으면 스킵

        isVisted[now.node] = true;

        // 무조건 이 반복문은 아예 외워두어야 함 
        for(int i=0; i<v[now.node].size(); i++) {   // 현재 방문하는 노드에 연결된 간선 개수만큼 방문해보는 것  
            Data next = v[now.node].at(i);          // 다음 방문하게 될 노드의 정보
            if(dist[next.node] > dist[now.node] + next.weight) {    
                dist[next.node] = dist[now.node] + next.weight;
                pq.push(Data(next.node, dist[next.node]));
            }
        }
    }

    for(int i=0; i<=N; i++) {
        cout << "dist " << i << ": " << dist[i] << "\n";
    }

    return 0;
}