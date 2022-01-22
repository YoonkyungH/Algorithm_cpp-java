// 웜홀
// 벨만포드

#include <iostream>
#include <vector>

#define INF 987654321

using namespace std;

struct Data {
    int e, t;
    Data() {};
    Data(int e, int t) : e(e), t(t){};
};

int N, M, W;    // 지점 개수 N, 도로 개수 M, 웜홀 개수 W
int TC;
int S, E, T;    // S(시작)-E(도착)  시간 T
// Data node[2500];
vector<Data> v[2500];
int dist[501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    while(TC--) {
        cin >> N >> M >> W;
        for(int i=1; i<=N; i++) {
            v[i].clear();
        }
        for(int i=1; i<=N; i++) {
            dist[i] = INF;
        }

        for(int i=0; i<M; i++) {
            cin >> S >> E >> T;
            v[S].push_back(Data(E, T));
            v[E].push_back(Data(S, T));
        }

        for(int i=0; i<W; i++) {
            cin >> S >> E >> T;
            v[S].push_back(Data(E, -T));
        }

        dist[1] = 0;
        bool minusCycle = false;
        for(int k=0; k<N; k++) {    // 지점만큼
            for(int i=1; i<=N; i++) {
                for(auto it : v[i]) {
                    int next = it.e;
                    int d = it.t;
                    if(dist[i] + d < dist[next]) {
                        dist[next] = dist[i] + d;
                        if(k == N-1) minusCycle = true;
                    }
                }
                // for(int j=0; j<v[i].size(); j++) {
                //     Data next = v[i].at(i);
                //     int d = next.t;
                //     if(dist[i] + d < dist[next.e]) {
                //         dist[next.e] = dist[i] + d;
                //         if(k == N-1) {
                //             minusCycle = true;
                //         }
                //     }
                // }
            }
        }

        if(minusCycle) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}