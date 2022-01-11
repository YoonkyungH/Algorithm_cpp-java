// 타임머신
// 벨만포드 알고리즘
// 2차원 for문

#include <iostream>

#define INF 9876543210  // long long 쓸 것임

struct Data {
    int a, b, c;
    Data() {};
    Data(int a, int b, long long c) : a(a), b(b), c(c) {};
};

using namespace std;

int N, M, A, B, C;
long long dist[501];    // 최대 도시 수 500, 범위 주의
Data list[6000];        // 버스 노선 수 6000

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;          // 도시, 버스 수

    for(int i=0; i<M; i++) {
        cin >> A >> B >> C; // 출발, 도착, 가중치
        list[i] = Data(A, B, C);
    }

    for(int i=1; i<=N; i++) {   // 초기화
        dist[i] = INF;
    }

    dist[1] = 0;    // 시작점의 거리를 0으로 초기화
    for(int i=1; i<N; i++) {    // N-1번 진행해라
        for(int j=0; j<M; j++) {
            if(dist[list[j].a] == INF) continue;                // a에서 출발할 수 있는 거리가 업데이트 되어있지 않다면 스킵
            if(dist[list[j].b] > dist[list[j].a] + list[j].c) { // 앞으로 진행하려는 거리값이 더 작으면 갱신해주기
                dist[list[j].b] = dist[list[j].a] + list[j].c;  // 갱신
            }
        }
    }

    bool isCycle = false;
    for(int j=0; j<M; j++) {    // 사이클 여부 판단. 다시 모든 간선들에 대해 순환을 돎
        if(dist[list[j].a] == INF) continue;
        if(dist[list[j].b] > dist[list[j].a] + list[j].c) { // 이때, 갱신되는 경우가 있다면 사이클이 있다는 것
            isCycle = true; break;
        }
    }

    if(isCycle) {
        cout << -1 << "\n";
    } else {
        for(int i=2; i<=N; i++) {
            if(dist[i] == INF) { cout << -1 << '\n'; }
            else { cout << dist[i] << '\n'; }
        }
    }

    return 0;
}
