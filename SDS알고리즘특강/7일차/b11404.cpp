// 플로이드
// 플로이드와샬 알고리즘
// 3차원 for문

#include <iostream>

#define INF 987654321

using namespace std;

int N, M;
int a, b, c;
int dp[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;   // 도시 수
    cin >> M;   // 버스 수

    for(int i=1; i<=N; i++) {   // 초기화
        for(int j=1; j<=N; j++) {
            dp[i][j] = INF;
        }
    }

    for(int i=0; i<M; i++) {
        cin >> a >> b >> c;
        if(dp[a][b] > c) dp[a][b] = c;  // 더 작은 비용으로 갱신 
    }

    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                if(i == j) continue;

                if(dp[i][k] == INF || dp[k][j] == INF) continue;    // 갈 수 없는 경우
                if(dp[i][j] > dp[i][k] + dp[k][j]) dp[i][j] = dp[i][k]+dp[k][j];
            }
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(dp[i][j] == INF) cout << 0 << " ";
            else cout << dp[i][j] << " ";
        } cout << '\n';
    }


    return 0;
}