// 타임머신
// 음의 가중치가 있을 경우 다익스트라 알고리즘을 적용하지 못함
// 그래서 벨만포드 알고리즘을 이용해야 함

#include <iostream>

#define INF 9876543210

using namespace std;

struct Data {
    int a, b, c;
    Data() {};
    Data(int a, int b, int c) : a(a), b(b), c(c) {};
};

int N, M;
int a, b, c;
Data bus[6000];
long long dist[501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    

    for(int i=0; i<M; i++) {
        cin >> a >> b >> c;
        bus[i] = Data(a, b, c);
    }
    
    for(int i=1; i<=N; i++) {
        dist[i] = INF;
    }

    dist[1] = 0;
    for(int i=1; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(dist[bus[j].a] == INF) continue;
            if(dist[bus[j].b] > dist[bus[j].a] + bus[j].c) {
                dist[bus[j].b] = dist[bus[j].a] + bus[j].c;
            }
        }
    }

    bool isCycle = false;
    for(int i=0; i<M; i++) {
        if(dist[bus[i].a] == INF) continue;
        if(dist[bus[i].b] > dist[bus[i].a] + bus[i].c) {    // 다 돌았음에도 불구하고 또 돌 수 있다는 것은 사이클이 존재한다는 것
            isCycle = true; break;
        }
    }

    if(isCycle) cout << "-1\n";
    else {
        for(int i=2; i<=N; i++) {
            if(dist[i] == INF) cout << "-1\n";
            else cout << dist[i] << '\n';
        }
    }

    return 0;
}